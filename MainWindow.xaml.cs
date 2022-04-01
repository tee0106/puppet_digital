//------------------------------------------------------------------------------
// <copyright file="MainWindow.xaml.cs" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

namespace Microsoft.Samples.Kinect.BodyBasics
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Media;
    using Microsoft.Speech.Synthesis;
    using Microsoft.CognitiveServices.SpeechRecognition;
    using System.Configuration;
    using Microsoft.Kinect;
    using System.Linq;
    using System.Windows.Media.Imaging;
    using System.Runtime.InteropServices;
    using WpfAnimatedGif;
    using System.Windows.Media.Animation;
    using System.Windows.Threading;
    using System.Net;
    using System.Net.Sockets;
    using System.Text;
    using System.Threading;
    using System.Threading.Tasks;
    using System.Windows.Forms;
    using System.IO;

    /// <summary>
    /// Interaction logic for MainWindow
    /// </summary>
    public partial class MainWindow : Window
    {
        double[] originalPowerSize = { 4, 21, 15, 5, 5, 5 };
        double[] powerSize = { 4, 21, 15, 5, 5, 5 };

        int zIndex = 0;
        int puppetid = -1;
        int changebg = 0;

        bool[] wearing = new bool[6];
        ulong[] bodyId = new ulong[6];
        ulong[] bodyStatus = new ulong[6];

        public delegate void ControlDialogueDelegate(String text);
        public ControlDialogueDelegate showDialogueDelegate;
        public ControlDialogueDelegate changeDialogueDelegate;

        public delegate void ControlResponseDelegate(String response);
        public ControlResponseDelegate showResponseDelegate;

        public delegate void ControlMagicDelegate(int spell);
        public ControlMagicDelegate showMagicDelegate;

        public delegate void ControlMusicDelegate(String path);
        public ControlMusicDelegate playMusicDelegate;

        public delegate void ControlPuppetDelegate(String facePath, String shoulderLeftPath, String shoulderRightPath, String upperArmLeftPath, String upperArmRightPath, String lowerArmLeftPath, String lowerArmRightPath, String handLeftPath, String handRightPath, String upperBodyPath, String lowerBodyPath, String thighLeftPath, String thighRightPath, String calfLeftPath, String calfRightPath, String footLeftPath, String footRightPath);
        public ControlPuppetDelegate changePuppetDelegate;

        public delegate void ControlSceneDelegate(String backgroundPath, String powerPath);
        public ControlSceneDelegate changeSceneDelegate;

        public delegate void ControlBackgroundDelegate(String url);
        public ControlBackgroundDelegate changeBackgroundDelegate;

        public delegate void ControlRecordDelegate();
        public ControlRecordDelegate startRecordDelegate;
        public ControlRecordDelegate stopRecordDelegate;

        MediaPlayer music = new MediaPlayer();

        bool speechRecognition = false;

        /// <summary>
        /// The microphone client
        /// </summary>
        private MicrophoneRecognitionClient micClient;

        private SpeechSynthesizer synth = new SpeechSynthesizer();

        /// <summary>
        /// Size of the RGB pixel in the bitmap
        /// </summary>
        private readonly int bytesPerPixel = (PixelFormats.Bgr32.BitsPerPixel + 7) / 8;

        /// <summary>
        /// Reader for depth/color/body index frames
        /// </summary>
        private MultiSourceFrameReader multiFrameSourceReader = null;

        /// <summary>
        /// Bitmap to display
        /// </summary>
        private WriteableBitmap bitmap = null;

        /// <summary>
        /// The depth values.
        /// </summary>
        ushort[] depthData = null;

        /// <summary>
        /// The body index values.
        /// </summary>
        byte[] bodyData = null;

        /// <summary>
        /// The RGB pixel values.
        /// </summary>
        byte[] colorData = null;

        /// <summary>
        /// The RGB pixel values used for the background removal (green-screen) effect.
        /// </summary>
        byte[] displayPixels = null;

        /// <summary>
        /// The color points used for the background removal (green-screen) effect.
        /// </summary>
        ColorSpacePoint[] colorPoints = null;

        BitmapImage face, shoulderLeft, shoulderRight, upperArmLeft, upperArmRight, lowerArmLeft, lowerArmRight, handLeft, handRight, upperBody, lowerBody, thighLeft, thighRight, calfLeft, calfRight, footLeft, footRight, background, power;

        /// <summary>
        /// Radius of drawn hand circles
        /// </summary>
        private const double HandSize = 30;

        /// <summary>
        /// Thickness of drawn joint lines
        /// </summary>
        private const double JointThickness = 3;

        /// <summary>
        /// Thickness of clip edge rectangles
        /// </summary>
        private const double ClipBoundsThickness = 10;

        /// <summary>
        /// Constant for clamping Z values of camera space points from being negative
        /// </summary>
        private const float InferredZPositionClamp = 0.1f;

        /// <summary>
        /// Active Kinect sensor
        /// </summary>
        private KinectSensor kinectSensor = null;

        /// <summary>
        /// Coordinate mapper to map one type of point to another
        /// </summary>
        private CoordinateMapper coordinateMapper = null;

        /// <summary>
        /// Reader for body frames
        /// </summary>
        private BodyFrameReader bodyFrameReader = null;

        /// <summary>
        /// Array for the bodies
        /// </summary>
        private Body[] bodies = null;

        /// <summary>
        /// Width of depth space
        /// </summary>
        private int depthWidth;

        /// <summary>
        /// Height of depth space
        /// </summary>
        private int depthHeight;

        /// <summary>
        /// Language Understanding Intelligent Service (LUIS)
        /// </summary>
        string LuisAppId = "0c055ca1-2d80-4c46-a306-3e384ec0e7a6";
        string LuisAppKey = "0394886ff6dc4510a1afcf8d9d80dd65";
        string LuisDomain = "westcentralus";

        /// <summary>
        /// Gets or sets a value indicating whether this instance is microphone client dictation.
        /// </summary>
        /// <value>
        /// <c>true</c> if this instance is microphone client dictation; otherwise, <c>false</c>.
        /// </value>
        public bool IsMicrophoneClientDictation { get; set; }

        /// <summary>
        /// Gets or sets subscription key
        /// </summary>
        public string SubscriptionKey
        {
            get
            {
                return "e099d6eb360343d18a3fad2f128ba7a6";
            }
        }

        /// <summary>
        /// Gets the current speech recognition mode.
        /// </summary>
        /// <value>
        /// The speech recognition mode.
        /// </value>
        private SpeechRecognitionMode Mode
        {
            get
            {
                return SpeechRecognitionMode.LongDictation;
            }
        }

        /// <summary>
        /// Gets the default locale.
        /// </summary>
        /// <value>
        /// The default locale.
        /// </value>
        private string DefaultLocale
        {
            //get { return "zh-TW"; }
            get { return "en-US"; }
        }

        /// <summary>
        /// Gets the Cognitive Service Authentication Uri.
        /// </summary>
        /// <value>
        /// The Cognitive Service Authentication Uri.  Empty if the global default is to be used.
        /// </value>
        private string AuthenticationUri
        {
            get
            {
                return ConfigurationManager.AppSettings["AuthenticationUri"];
            }
        }

        /// <summary>
        /// Raises the System.Windows.Window.Closed event.
        /// </summary>
        /// <param name="e">An System.EventArgs that contains the event data.</param>
        protected override void OnClosed(EventArgs e)
        {
            if (null != this.micClient)
            {
                this.micClient.Dispose();
            }

            base.OnClosed(e);
        }

        /// <summary>
        /// Initializes a fresh audio session.
        /// </summary>
        private void Initialize()
        {
            this.IsMicrophoneClientDictation = true;
        }

        /// <summary>
        /// Creates a new microphone reco client without LUIS intent support.
        /// </summary>
        private void CreateMicrophoneRecoClient()
        {
            this.micClient = SpeechRecognitionServiceFactory.CreateMicrophoneClient(
                this.Mode,
                this.DefaultLocale,
                this.SubscriptionKey);
            this.micClient.AuthenticationUri = this.AuthenticationUri;

            // Event handlers for speech recognition results
            this.micClient.OnMicrophoneStatus += this.OnMicrophoneStatus;
            this.micClient.OnPartialResponseReceived += this.OnPartialResponseReceivedHandler;
            if (this.Mode == SpeechRecognitionMode.LongDictation)
            {
                this.micClient.OnResponseReceived += this.OnMicDictationResponseReceivedHandler;
            }

            this.micClient.OnConversationError += this.OnConversationErrorHandler;
        }

        /// <summary>
        /// Writes the response result.
        /// </summary>
        /// <param name="e">The <see cref="SpeechResponseEventArgs"/> instance containing the event data.</param>
        private void WriteResponseResult(SpeechResponseEventArgs e)
        {
            if (e.PhraseResponse.Results.Length == 0)
            {
                Console.WriteLine("No phrase response is available.");
            }
            else
            {
                for (int i = 0; i < e.PhraseResponse.Results.Length; i++)
                {
                    Console.WriteLine(
                        "[{0}] Confidence={1}, Text=\"{2}\"", 
                        i, 
                        e.PhraseResponse.Results[i].Confidence,
                        e.PhraseResponse.Results[i].DisplayText);

                    LanguageProcessing(e.PhraseResponse.Results[i].DisplayText);
                }
            }
        }

        private void LanguageProcessing(string text)
        {
            try
            {
                Cognitive.LUIS.LuisClient luisClient = new Cognitive.LUIS.LuisClient(LuisAppId, LuisAppKey, true, LuisDomain);

                var query = luisClient.Predict(text).Result;

                if (query.TopScoringIntent.Name == "Dialogue" && query.Entities.FirstOrDefault().Value != null)
                {
                    switch (query.Entities.FirstOrDefault().Value.FirstOrDefault().Name)
                    {
                        case "Greet":
                            /*showResponseDelegate.Invoke("Hi, nice to meet you!");
                            Console.WriteLine("Hi, nice to meet you!");
                            synth.Speak("Hi, nice to meet you!");*/
                            break;

                        case "Bye":
                            /*showResponseDelegate.Invoke("Goodbye!");
                            Console.WriteLine("Goodbye!");
                            synth.Speak("Goodbye!");*/
                            break;

                        case "Shit":
                            /*showResponseDelegate.Invoke("Fuck you.");
                            Console.WriteLine("Fuck you.");
                            synth.Speak("Fuck you.");*/
                            break;

                        case "Agree":
                            /*showResponseDelegate.Invoke("I agree.");
                            Console.WriteLine("I agree.");
                            synth.Speak("I agree.");*/
                            break;

                        case "Disagree":
                            /*showResponseDelegate.Invoke("Why not?");
                            Console.WriteLine("Why not?");
                            synth.Speak("Why not?");*/
                            break;

                        case "Weather":
                            /*showResponseDelegate.Invoke("It's rainy.");
                            Console.WriteLine("It's rainy.");
                            synth.Speak("It's rainy.");*/
                            showMagicDelegate.Invoke(0);
                            break;

                        case "Place":
                            /*showResponseDelegate.Invoke("I'm in the library.");
                            Console.WriteLine("I'm in the library.");
                            synth.Speak("I'm in the library.");*/
                            for (int i = 0; i < 6; i++)
                            {
                                powerSize[i] = 4;
                            }
                            showMagicDelegate.Invoke(4);
                            changeSceneDelegate.Invoke(@"/Images/Background/Library.jpg", @"/Images/Prop/Book.png");
                            break;

                        case "Food":
                            /*showResponseDelegate.Invoke("I want a burger.");
                            Console.WriteLine("I want a burger.");
                            synth.Speak("I want a burger.");*/
                            for (int i = 0; i < 6; i++)
                            {
                                powerSize[i] = 2.5;
                            }
                            showMagicDelegate.Invoke(4);
                            changeSceneDelegate.Invoke(@"/Images/Background/Restaurant.jpg", @"/Images/Prop/Burger.png");
                            break;

                        case "Time":
                            /*showResponseDelegate.Invoke("It's midnight now.");
                            Console.WriteLine("It's midnight now.");
                            synth.Speak("It's midnight now.");*/
                            for (int i = 0; i < 6; i++)
                            {
                                powerSize[i] = 5;
                            }
                            showMagicDelegate.Invoke(4);
                            changeSceneDelegate.Invoke(@"/Images/Background/Night.gif", @"/Images/I/Fire.gif");
                            break;

                        default:
                            /*showResponseDelegate.Invoke(text);
                            Console.WriteLine(text);
                            synth.Speak(text);*/
                            break;
                    }
                }
                else if (query.TopScoringIntent.Name == "Spell" && query.Entities.FirstOrDefault().Value != null)
                {
                    switch (query.Entities.FirstOrDefault().Value.FirstOrDefault().Name)
                    {
                        case "Water":
                            /*showResponseDelegate.Invoke("The flood is coming.");
                            Console.WriteLine("The flood is coming.");
                            synth.Speak("The flood is coming.");*/
                            showMagicDelegate.Invoke(1);
                            break;

                        case "Transform":
                            /*showResponseDelegate.Invoke("Suit up!");
                            Console.WriteLine("Suit up!");
                            synth.Speak("Suit up!");*/
                            playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                            changePuppetDelegate.Invoke(@"/Images/II/Ironman.png", @"/Images/II/PauldronLeft.png", @"/Images/II/PauldronRight.png", @"/Images/II/VambraceLeft.png", @"/Images/II/VambraceRight.png", @"/Images/II/SpringLeft.png", @"/Images/II/SpringRight.png", @"/Images/II/GloveLeft.png", @"/Images/II/GloveRight.png", @"/Images/II/Armor.png", @"/Images/II/Fauld.png", @"/Images/II/CuisseLeft.png", @"/Images/II/CuisseRight.png", @"/Images/II/SpringLeft.png", @"/Images/II/SpringRight.png", @"/Images/II/JordanLeft.png", @"/Images/II/JordanRight.png");
                            break;

                        case "Invisible":
                            /*showResponseDelegate.Invoke("You can't see me!");
                            Console.WriteLine("You can't see me!");
                            synth.Speak("You can't see me!");*/
                            showMagicDelegate.Invoke(2);
                            break;

                        case "Visible":
                            /*showResponseDelegate.Invoke("You got me!");
                            Console.WriteLine("You got me!");
                            synth.Speak("You got me!");*/
                            showMagicDelegate.Invoke(3);
                            break;

                        case "Recover":
                            /*showResponseDelegate.Invoke("Initialization!");
                            Console.WriteLine("Initialization!");
                            synth.Speak("Initialization!");*/
                            changePuppetDelegate.Invoke(@"/Images/I/0.png", @"/Images/I/1.png", @"/Images/I/2.png", @"/Images/I/3.png", @"/Images/I/4.png", @"/Images/I/5.png", @"/Images/I/6.png", @"/Images/I/7.png", @"/Images/I/8.png", @"/Images/I/9.png", @"/Images/I/10.png", @"/Images/I/11.png", @"/Images/I/12.png", @"/Images/I/5.png", @"/Images/I/6.png", @"/Images/I/13.png", @"/Images/I/14.png");
                            for (int i = 0; i < 6; i++)
                            {
                                powerSize[i] = originalPowerSize[i];
                            }
                            changeSceneDelegate.Invoke(@"/Images/Background/Screen.jpg", "");
                            playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transfer.mp3");
                            showMagicDelegate.Invoke(4);
                            break;

                        case "StartRecord":
                            showResponseDelegate.Invoke("Action!");
                            Console.WriteLine("Action!");
                            synth.Speak("Action!");
                            startRecordDelegate.Invoke();
                            break;

                        case "StopRecord":
                            showResponseDelegate.Invoke("Cut!");
                            Console.WriteLine("Cut!");
                            synth.Speak("Cut!");
                            stopRecordDelegate.Invoke();
                            break;

                        default:
                            showResponseDelegate.Invoke(text);
                            Console.WriteLine(text);
                            synth.Speak(text);
                            break;
                    }
                }
                else
                {
                    showResponseDelegate.Invoke(text);
                    Console.WriteLine(text);
                    synth.Speak(text);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
                showResponseDelegate.Invoke(text);
                Console.WriteLine(text);
                synth.Speak(text);
            }
        }
        private void ScreenshotButton_Click(object sender, RoutedEventArgs e)//鋼鐵人
        {
            playMusicDelegate.Invoke(@"C:\Users\USER\source\repos\puppet-based-digital-theater-Dev\Audios\Transform.mp3");
            //換鋼鐵人
            changePuppetDelegate.Invoke(@"/Images/II/Ironman.png", @"/Images/II/PauldronLeft.png", @"/Images/II/PauldronRight.png", @"/Images/II/VambraceLeft.png", @"/Images/II/VambraceRight.png", @"/Images/II/SpringLeft.png", @"/Images/II/SpringRight.png", @"/Images/II/GloveLeft.png", @"/Images/II/GloveRight.png", @"/Images/II/Armor.png", @"/Images/II/Fauld.png", @"/Images/II/CuisseLeft.png", @"/Images/II/CuisseRight.png", @"/Images/II/SpringLeft.png", @"/Images/II/SpringRight.png", @"/Images/II/JordanLeft.png", @"/Images/II/JordanRight.png");
            //關掉特效
            Smile.Opacity = 0;
            PowerLeft.Opacity = 0;
            PowerLeft3.Opacity = 0;
            PowerRight3.Opacity = 0;
            PowerLeft4.Opacity = 0;
            BlackPanther.Opacity = 0;
            PowerRight6.Opacity = 0;
            PowerLeft6.Opacity = 0;
            puppetid = 1;
            People.Opacity = 0;
        }
        private void ScreenshotButton_Click2(object sender, RoutedEventArgs e)//黑武士
        {
            playMusicDelegate.Invoke(@"C:\Users\USER\source\repos\puppet-based-digital-theater-Dev\Audios\Transform.mp3");
            //換黑武士
            changePuppetDelegate.Invoke(@"/Images/III/0.png", @"/Images/III/1.png", @"/Images/III/2.png", @"/Images/III/3.png", @"/Images/III/4.png", @"/Images/III/5.png", @"/Images/III/6.png", @"/Images/III/7.png", @"/Images/III/8.png", @"/Images/III/9.png", @"/Images/III/10.png", @"/Images/III/11.png", @"/Images/III/12.png", @"/Images/III/13.png", @"/Images/III/14.png", @"/Images/III/15.png", @"/Images/III/16.png");
            //關掉其他id的handstate
            Smile.Opacity = 0;
            PowerLeft.Opacity = 0;
            Facechange2.Opacity = 0;
            PowerLeft3.Opacity = 0;
            PowerRight3.Opacity = 0;
            PowerLeft4.Opacity = 0;
            BlackPanther.Opacity = 0;
            PowerRight6.Opacity = 0;
            PowerLeft6.Opacity = 0;
            puppetid = 2;
            People.Opacity = 0;
        }
        private void ScreenshotButton_Click3(object sender, RoutedEventArgs e)//透明人
        {
            playMusicDelegate.Invoke(@"C:\Users\USER\source\repos\puppet-based-digital-theater-Dev\Audios\Transform.mp3");
            //關掉其他id的handstate
            Smile.Opacity = 0;
            PowerLeft.Opacity = 0;
            Facechange2.Opacity = 0;
            PowerLeft2.Opacity = 0;
            PowerRight2.Opacity = 0;
            PowerLeft4.Opacity = 0;
            BlackPanther.Opacity = 0;
            PowerRight6.Opacity = 0;
            PowerLeft6.Opacity = 0;
            //換透明人
            changePuppetDelegate.Invoke(@"/Images/IV/0.png", @"/Images/IV/1.png", @"/Images/IV/2.png", @"/Images/IV/3.png", @"/Images/IV/4.png", @"/Images/IV/5.png", @"/Images/IV/6.png", @"/Images/IV/7.png", @"/Images/IV/8.png", @"/Images/IV/9.png", @"/Images/IV/10.png", @"/Images/IV/11.png", @"/Images/IV/12.png", @"/Images/IV/7.png", @"/Images/IV/8.png", @"/Images/IV/13.png", @"/Images/IV/14.png");
            puppetid = 3;
            People.Opacity = 0;
        }
        private void ScreenshotButton_Click4(object sender, RoutedEventArgs e)//黑豹
        {
            playMusicDelegate.Invoke(@"C:\Users\USER\source\repos\puppet-based-digital-theater-Dev\Audios\Transform.mp3");
            //關掉其他id的handstate
            Smile.Opacity = 0;
            PowerLeft.Opacity = 0;
            Facechange2.Opacity = 0;
            PowerLeft2.Opacity = 0;
            PowerRight2.Opacity = 0;
            PowerLeft3.Opacity = 0;
            PowerRight3.Opacity = 0;
            PowerLeft4.Opacity = 0;
            PowerRight6.Opacity = 0;
            PowerLeft6.Opacity = 0;
            //
            changePuppetDelegate.Invoke(@"/Images/V/0.png", @"/Images/V/3.png", @"/Images/V/4.png", @"/Images/V/5.png", @"/Images/V/6.png", @"/Images/V/5.png", @"/Images/V/6.png", @"/Images/V/7.png", @"/Images/V/8.png", @"/Images/V/9.png", @"/Images/V/10.png", @"/Images/V/11.png", @"/Images/V/12.png", @"/Images/V/13.png", @"/Images/V/14.png", @"/Images/V/15.png", @"/Images/V/16.png");
            puppetid = 4;
            People.Opacity = 0;
        }
        private void ScreenshotButton_Click5(object sender, RoutedEventArgs e)//驚奇隊長
        {
            playMusicDelegate.Invoke(@"C:\Users\USER\source\repos\puppet-based-digital-theater-Dev\Audios\Transform.mp3");
            //關掉其他id的handstate
            Smile.Opacity = 0;
            PowerLeft.Opacity = 0;
            Facechange2.Opacity = 0;
            PowerLeft2.Opacity = 0;
            PowerRight2.Opacity = 0;
            PowerLeft3.Opacity = 0;
            PowerRight3.Opacity = 0;
            PowerLeft4.Opacity = 0;
            BlackPanther.Opacity = 0;
            //換驚奇隊長
            changePuppetDelegate.Invoke(@"/Images/VI/0.png", @"/Images/VI/3.png", @"/Images/VI/4.png", @"/Images/VI/5.png", @"/Images/VI/6.png", @"/Images/VI/5.png", @"/Images/VI/6.png", @"/Images/VI/7.png", @"/Images/VI/8.png", @"/Images/VI/9.png", @"/Images/VI/10.png", @"/Images/VI/11.png", @"/Images/VI/12.png", @"/Images/VI/15.png", @"/Images/VI/15.png", @"/Images/VI/13.png", @"/Images/VI/14.png");
            puppetid = 5;
            People.Opacity = 0;
        }

        /// <summary>
        /// Called when a final response is received;
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="SpeechResponseEventArgs"/> instance containing the event data.</param>
        private void OnMicDictationResponseReceivedHandler(object sender, SpeechResponseEventArgs e)
        {
            if (e.PhraseResponse.RecognitionStatus == RecognitionStatus.EndOfDictation ||
                e.PhraseResponse.RecognitionStatus == RecognitionStatus.DictationEndSilenceTimeout)
            {
                Dispatcher.Invoke(
                    (Action)(() =>
                    {
                        // we got the final result, so it we can end the mic reco.  No need to do this
                        // for dataReco, since we already called endAudio() on it as soon as we were done
                        // sending all the data.
                        this.micClient.EndMicAndRecognition();
                    }));
            }

            this.WriteResponseResult(e);
        }

        /// <summary>
        /// Called when a partial response is received.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="PartialSpeechResponseEventArgs"/> instance containing the event data.</param>
        private void OnPartialResponseReceivedHandler(object sender, PartialSpeechResponseEventArgs e)
        {
            Console.WriteLine("--- Partial result received by OnPartialResponseReceivedHandler() ---");
        }

        /// <summary>
        /// Called when an error is received.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="SpeechErrorEventArgs"/> instance containing the event data.</param>
        private void OnConversationErrorHandler(object sender, SpeechErrorEventArgs e)
        {
            Console.WriteLine("--- Error received by OnConversationErrorHandler() ---");
        }

        /// <summary>
        /// Called when the microphone status has changed.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="MicrophoneEventArgs"/> instance containing the event data.</param>
        private void OnMicrophoneStatus(object sender, MicrophoneEventArgs e)
        {
            Dispatcher.Invoke(() =>
            {
                Console.WriteLine("--- Microphone status change received by OnMicrophoneStatus() ---");
                Console.WriteLine("********* Microphone status: {0} *********", e.Recording);
                if (e.Recording)
                {
                    Console.WriteLine("Please start speaking.");
                }

            });
        }

        /// <summary>
        /// Initializes a new instance of the MainWindow class.
        /// </summary>
        public MainWindow()
        {
            var waitingTask = new Task<int>(TCPServer);
            waitingTask.Start();

            //synth.SelectVoice("Microsoft Server Speech Text to Speech Voice (zh-TW, HanHan)");
            synth.SelectVoice("Microsoft Server Speech Text to Speech Voice (en-US, Helen)");
            //synth.SelectVoice("Microsoft Server Speech Text to Speech Voice (en-US, ZiraPro)");
            synth.SetOutputToDefaultAudioDevice();
            synth.Volume = 100;
            synth.Rate = -3;

            // one sensor is currently supported
            this.kinectSensor = KinectSensor.GetDefault();

            this.multiFrameSourceReader = this.kinectSensor.OpenMultiSourceFrameReader(FrameSourceTypes.Depth | FrameSourceTypes.Color | FrameSourceTypes.BodyIndex);

            this.multiFrameSourceReader.MultiSourceFrameArrived += this.Reader_MultiSourceFrameArrived;

            // get the coordinate mapper
            this.coordinateMapper = this.kinectSensor.CoordinateMapper;

            // get the depth (display) extents
            FrameDescription depthFrameDescription = this.kinectSensor.DepthFrameSource.FrameDescription;

            // get size of joint space
            this.depthWidth = depthFrameDescription.Width;
            this.depthHeight = depthFrameDescription.Height;

            // open the reader for the body frames
            this.bodyFrameReader = this.kinectSensor.BodyFrameSource.OpenReader();

            // open the sensor
            this.kinectSensor.Open();

            // initialize the components (controls) of the window
            this.InitializeComponent();
            this.Initialize();

            if (this.bodyFrameReader != null)
            {
                this.bodyFrameReader.FrameArrived += this.Reader_FrameArrived;
            }

            this.showDialogueDelegate = ShowDialogue;
            this.changeDialogueDelegate = ChangeDialogue;
            this.showResponseDelegate = ShowResponse;
            this.showMagicDelegate = ShowMagic;
            this.playMusicDelegate = PlayMusic;
            this.changePuppetDelegate = ChangePuppet;
            this.changeSceneDelegate = ChangeScene;
            this.changeBackgroundDelegate = ChangeBackground;
            this.startRecordDelegate = StartRecord;
            this.stopRecordDelegate = StopRecord;
        }

        /// <summary>
        /// Gets the bitmap to display
        /// </summary>
        public ImageSource ImageSource
        {
            get
            {
                return this.bitmap;
            }
        }

        /// <summary>
        /// Execute start up tasks
        /// </summary>
        /// <param name="sender">object sending the event</param>
        /// <param name="e">event arguments</param>
        private void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
        }

        /// <summary>
        /// Execute shutdown tasks
        /// </summary>
        /// <param name="sender">object sending the event</param>
        /// <param name="e">event arguments</param>
        private void MainWindow_Closing(object sender, CancelEventArgs e)
        {
            if (this.multiFrameSourceReader != null)
            {
                // MultiSourceFrameReder is IDisposable
                this.multiFrameSourceReader.Dispose();
                this.multiFrameSourceReader = null;
            }

            if (this.bodyFrameReader != null)
            {
                // BodyFrameReader is IDisposable
                this.bodyFrameReader.Dispose();
                this.bodyFrameReader = null;
            }

            if (this.kinectSensor != null)
            {
                this.kinectSensor.Close();
                this.kinectSensor = null;
            }
        }

        private void Reader_MultiSourceFrameArrived(object sender, MultiSourceFrameArrivedEventArgs e)
        {
            var reference = e.FrameReference.AcquireFrame();

            using (var colorFrame = reference.ColorFrameReference.AcquireFrame())
            using (var depthFrame = reference.DepthFrameReference.AcquireFrame())
            using (var bodyIndexFrame = reference.BodyIndexFrameReference.AcquireFrame())
            {
                if (colorFrame != null && depthFrame != null && bodyIndexFrame != null)
                {
                    People.Source = this.RemoveBackground(colorFrame, depthFrame, bodyIndexFrame);
                }
            }
        }

        /// <summary>
        /// Converts a depth frame to the corresponding System.Windows.Media.Imaging.BitmapSource and removes the background (green-screen effect).
        /// </summary>
        /// <param name="colorFrame">The specified color frame.</param>
        /// <param name="depthFrame">The specified depth frame.</param>
        /// <param name="bodyIndexFrame">The specified body index frame.</param>
        /// <returns>The corresponding System.Windows.Media.Imaging.BitmapSource representation of image.</returns>
        public BitmapSource RemoveBackground(ColorFrame colorFrame, DepthFrame depthFrame, BodyIndexFrame bodyIndexFrame)
        {
            int colorWidth = colorFrame.FrameDescription.Width;
            int colorHeight = colorFrame.FrameDescription.Height;

            int depthWidth = depthFrame.FrameDescription.Width;
            int depthHeight = depthFrame.FrameDescription.Height;

            int bodyIndexWidth = bodyIndexFrame.FrameDescription.Width;
            int bodyIndexHeight = bodyIndexFrame.FrameDescription.Height;

            if (displayPixels == null)
            {
                depthData = new ushort[depthWidth * depthHeight];
                bodyData = new byte[depthWidth * depthHeight];
                colorData = new byte[colorWidth * colorHeight * bytesPerPixel];
                displayPixels = new byte[depthWidth * depthHeight * bytesPerPixel];
                colorPoints = new ColorSpacePoint[depthWidth * depthHeight];
                bitmap = new WriteableBitmap(depthWidth, depthHeight, 96.0, 96.0, PixelFormats.Bgra32, null);
            }

            if (((depthWidth * depthHeight) == depthData.Length) && ((bodyIndexWidth * bodyIndexHeight) == bodyData.Length) && ((colorWidth * colorHeight * bytesPerPixel) == colorData.Length))
            {
                depthFrame.CopyFrameDataToArray(depthData);

                if (colorFrame.RawColorImageFormat == ColorImageFormat.Bgra)
                {
                    colorFrame.CopyRawFrameDataToArray(colorData);
                }
                else
                {
                    colorFrame.CopyConvertedFrameDataToArray(colorData, ColorImageFormat.Bgra);
                }

                bodyIndexFrame.CopyFrameDataToArray(bodyData);

                coordinateMapper.MapDepthFrameToColorSpace(depthData, colorPoints);

                Array.Clear(displayPixels, 0, displayPixels.Length);

                for (int y = 0; y < depthHeight; ++y)
                {
                    for (int x = 0; x < depthWidth; ++x)
                    {
                        int depthIndex = (y * depthWidth) + x;

                        byte player = bodyData[depthIndex];

                        if (player != 0xff)
                        {
                            ColorSpacePoint colorPoint = colorPoints[depthIndex];

                            int colorX = (int)Math.Floor(colorPoint.X + 0.5);
                            int colorY = (int)Math.Floor(colorPoint.Y + 0.5);

                            if ((colorX >= 0) && (colorX < colorWidth) && (colorY >= 0) && (colorY < colorHeight))
                            {
                                int colorIndex = ((colorY * colorWidth) + colorX) * bytesPerPixel;
                                int displayIndex = depthIndex * bytesPerPixel;

                                // RGB三原色
                                displayPixels[displayIndex + 0] = colorData[colorIndex];
                                displayPixels[displayIndex + 1] = colorData[colorIndex + 1];
                                displayPixels[displayIndex + 2] = colorData[colorIndex + 2];
                                displayPixels[displayIndex + 3] = 0xff;
                            }
                        }
                    }
                }

                bitmap.Lock();

                Marshal.Copy(displayPixels, 0, bitmap.BackBuffer, displayPixels.Length);
                bitmap.AddDirtyRect(new Int32Rect(0, 0, depthWidth, depthHeight));
                bitmap.Unlock();
            }
            return bitmap;
        }

        /// <summary>
        /// Handles the body frame data arriving from the sensor
        /// </summary>
        /// <param name="sender">object sending the event</param>
        /// <param name="e">event arguments</param>
        private void Reader_FrameArrived(object sender, BodyFrameArrivedEventArgs e)
        {
            bool dataReceived = false;

            using (BodyFrame bodyFrame = e.FrameReference.AcquireFrame())
            {
                if (bodyFrame != null)
                {
                    if (this.bodies == null)
                    {
                        this.bodies = new Body[bodyFrame.BodyCount];
                    }

                    // The first time GetAndRefreshBodyData is called, Kinect will allocate each Body in the array.
                    // As long as those body objects are not disposed and not set to null in the array,
                    // those body objects will be re-used.
                    bodyFrame.GetAndRefreshBodyData(this.bodies);
                    dataReceived = true;
                }
            }

            if (dataReceived)
            {
                    foreach (Body body in this.bodies)
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            bodyStatus[i] = bodies[i].TrackingId;
                        }

                        if (body.IsTracked)
                        {
                            IReadOnlyDictionary<JointType, Joint> joints = body.Joints;

                            // convert the joint points to depth (display) space
                            Dictionary<JointType, Point> jointPoints = new Dictionary<JointType, Point>();

                            foreach (JointType jointType in joints.Keys)
                            {
                                // sometimes the depth(Z) of an inferred joint may show as negative
                                // clamp down to 0.1f to prevent coordinatemapper from returning (-Infinity, -Infinity)
                                CameraSpacePoint position = joints[jointType].Position;
                                if (position.Z < 0)
                                {
                                    position.Z = InferredZPositionClamp;
                                }

                                DepthSpacePoint depthSpacePoint = this.coordinateMapper.MapCameraPointToDepthSpace(position);
                                jointPoints[jointType] = new Point(depthSpacePoint.X, depthSpacePoint.Y);
                            }
                            People.Opacity = 1;

                            // 求兩節點間的長度
                            double faceLength = Math.Sqrt(Math.Pow(jointPoints[JointType.Head].X - jointPoints[JointType.Neck].X, 2) + Math.Pow(jointPoints[JointType.Head].Y - jointPoints[JointType.Neck].Y, 2));
                            double shoulderLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.ShoulderLeft].X, 2) + Math.Pow(jointPoints[JointType.SpineShoulder].Y - jointPoints[JointType.ShoulderLeft].Y, 2));
                            double shoulderRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.ShoulderRight].X, 2) + Math.Pow(jointPoints[JointType.SpineShoulder].Y - jointPoints[JointType.ShoulderRight].Y, 2));
                            double upperArmLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.ShoulderLeft].X - jointPoints[JointType.ElbowLeft].X, 2) + Math.Pow(jointPoints[JointType.ShoulderLeft].Y - jointPoints[JointType.ElbowLeft].Y, 2));
                            double upperArmRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.ShoulderRight].X - jointPoints[JointType.ElbowRight].X, 2) + Math.Pow(jointPoints[JointType.ShoulderRight].Y - jointPoints[JointType.ElbowRight].Y, 2));
                            double lowerArmLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.ElbowLeft].X - jointPoints[JointType.WristLeft].X, 2) + Math.Pow(jointPoints[JointType.ElbowLeft].Y - jointPoints[JointType.WristLeft].Y, 2));
                            double lowerArmRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.ElbowRight].X - jointPoints[JointType.WristRight].X, 2) + Math.Pow(jointPoints[JointType.ElbowRight].Y - jointPoints[JointType.WristRight].Y, 2));
                            double handLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.WristLeft].X - jointPoints[JointType.HandLeft].X, 2) + Math.Pow(jointPoints[JointType.WristLeft].Y - jointPoints[JointType.HandLeft].Y, 2));
                            double handRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.WristRight].X - jointPoints[JointType.HandRight].X, 2) + Math.Pow(jointPoints[JointType.WristRight].Y - jointPoints[JointType.HandRight].Y, 2));
                            double upperBodyLength = Math.Sqrt(Math.Pow(jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.SpineMid].X, 2) + Math.Pow(jointPoints[JointType.SpineShoulder].Y - jointPoints[JointType.SpineMid].Y, 2));
                            double lowerBodyLength = Math.Sqrt(Math.Pow(jointPoints[JointType.SpineMid].X - jointPoints[JointType.SpineBase].X, 2) + Math.Pow(jointPoints[JointType.SpineMid].Y - jointPoints[JointType.SpineBase].Y, 2));
                            double thighLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.HipLeft].X - jointPoints[JointType.KneeLeft].X, 2) + Math.Pow(jointPoints[JointType.HipLeft].Y - jointPoints[JointType.KneeLeft].Y, 2));
                            double thighRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.HipRight].X - jointPoints[JointType.KneeRight].X, 2) + Math.Pow(jointPoints[JointType.HipRight].Y - jointPoints[JointType.KneeRight].Y, 2));
                            double calfLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.KneeLeft].X - jointPoints[JointType.AnkleLeft].X, 2) + Math.Pow(jointPoints[JointType.KneeLeft].Y - jointPoints[JointType.AnkleLeft].Y, 2));
                            double calfRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.KneeRight].X - jointPoints[JointType.AnkleRight].X, 2) + Math.Pow(jointPoints[JointType.KneeRight].Y - jointPoints[JointType.AnkleRight].Y, 2));
                            double footLeftLength = Math.Sqrt(Math.Pow(jointPoints[JointType.AnkleLeft].X - jointPoints[JointType.FootLeft].X, 2) + Math.Pow(jointPoints[JointType.AnkleLeft].Y - jointPoints[JointType.FootLeft].Y, 2));
                            double footRightLength = Math.Sqrt(Math.Pow(jointPoints[JointType.AnkleRight].X - jointPoints[JointType.FootRight].X, 2) + Math.Pow(jointPoints[JointType.AnkleRight].Y - jointPoints[JointType.FootRight].Y, 2));

                            // 用三角函數求出旋轉角度
                            double faceAngle, shoulderLeftAngle, shoulderRightAngle, upperArmLeftAngle, upperArmRightAngle, upperBodyAngle, lowerBodyAngle, thighLeftAngle, thighRightAngle, calfLeftAngle, calfRightAngle, footLeftAngle, footRightAngle, lowerArmLeftAngle, lowerArmRightAngle, handLeftAngle, handRightAngle;
                            if (jointPoints[JointType.Head].Y <= jointPoints[JointType.Neck].Y)
                            {
                                faceAngle = Math.Asin((jointPoints[JointType.Head].X - jointPoints[JointType.Neck].X) / faceLength) * 180 / Math.PI;
                            }
                            else
                            {
                                faceAngle = 180 - Math.Asin((jointPoints[JointType.Head].X - jointPoints[JointType.Neck].X) / faceLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.SpineShoulder].Y <= jointPoints[JointType.ShoulderLeft].Y)
                            {
                                shoulderLeftAngle = Math.Asin((jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.ShoulderLeft].X) / shoulderLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                shoulderLeftAngle = 180 - Math.Asin((jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.ShoulderLeft].X) / shoulderLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.SpineShoulder].Y <= jointPoints[JointType.ShoulderRight].Y)
                            {
                                shoulderRightAngle = Math.Asin((jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.ShoulderRight].X) / shoulderRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                shoulderRightAngle = 180 - Math.Asin((jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.ShoulderRight].X) / shoulderRightLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.ShoulderLeft].Y <= jointPoints[JointType.ElbowLeft].Y)
                            {
                                upperArmLeftAngle = Math.Asin((jointPoints[JointType.ShoulderLeft].X - jointPoints[JointType.ElbowLeft].X) / upperArmLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                upperArmLeftAngle = 180 - Math.Asin((jointPoints[JointType.ShoulderLeft].X - jointPoints[JointType.ElbowLeft].X) / upperArmLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.ShoulderRight].Y <= jointPoints[JointType.ElbowRight].Y)
                            {
                                upperArmRightAngle = Math.Asin((jointPoints[JointType.ShoulderRight].X - jointPoints[JointType.ElbowRight].X) / upperArmRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                upperArmRightAngle = 180 - Math.Asin((jointPoints[JointType.ShoulderRight].X - jointPoints[JointType.ElbowRight].X) / upperArmRightLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.ElbowLeft].Y <= jointPoints[JointType.WristLeft].Y)
                            {
                                lowerArmLeftAngle = Math.Asin((jointPoints[JointType.ElbowLeft].X - jointPoints[JointType.WristLeft].X) / lowerArmLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                lowerArmLeftAngle = 180 - Math.Asin((jointPoints[JointType.ElbowLeft].X - jointPoints[JointType.WristLeft].X) / lowerArmLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.ElbowRight].Y <= jointPoints[JointType.WristRight].Y)
                            {
                                lowerArmRightAngle = Math.Asin((jointPoints[JointType.ElbowRight].X - jointPoints[JointType.WristRight].X) / lowerArmRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                lowerArmRightAngle = 180 - Math.Asin((jointPoints[JointType.ElbowRight].X - jointPoints[JointType.WristRight].X) / lowerArmRightLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.WristLeft].Y <= jointPoints[JointType.HandLeft].Y)
                            {
                                handLeftAngle = Math.Asin((jointPoints[JointType.WristLeft].X - jointPoints[JointType.HandLeft].X) / handLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                handLeftAngle = 180 - Math.Asin((jointPoints[JointType.WristLeft].X - jointPoints[JointType.HandLeft].X) / handLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.WristRight].Y <= jointPoints[JointType.HandRight].Y)
                            {
                                handRightAngle = Math.Asin((jointPoints[JointType.WristRight].X - jointPoints[JointType.HandRight].X) / handRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                handRightAngle = 180 - Math.Asin((jointPoints[JointType.WristRight].X - jointPoints[JointType.HandRight].X) / handRightLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.SpineShoulder].Y <= jointPoints[JointType.SpineMid].Y)
                            {
                                upperBodyAngle = Math.Asin((jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.SpineMid].X) / upperBodyLength) * 180 / Math.PI;
                            }
                            else
                            {
                                upperBodyAngle = 180 - Math.Asin((jointPoints[JointType.SpineShoulder].X - jointPoints[JointType.SpineMid].X) / upperBodyLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.SpineMid].Y <= jointPoints[JointType.SpineBase].Y)
                            {
                                lowerBodyAngle = Math.Asin((jointPoints[JointType.SpineMid].X - jointPoints[JointType.SpineBase].X) / lowerBodyLength) * 180 / Math.PI;
                            }
                            else
                            {
                                lowerBodyAngle = 180 - Math.Asin((jointPoints[JointType.SpineMid].X - jointPoints[JointType.SpineBase].X) / lowerBodyLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.HipLeft].Y <= jointPoints[JointType.KneeLeft].Y)
                            {
                                thighLeftAngle = Math.Asin((jointPoints[JointType.HipLeft].X - jointPoints[JointType.KneeLeft].X) / thighLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                thighLeftAngle = 180 - Math.Asin((jointPoints[JointType.HipLeft].X - jointPoints[JointType.KneeLeft].X) / thighLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.HipRight].Y <= jointPoints[JointType.KneeRight].Y)
                            {
                                thighRightAngle = Math.Asin((jointPoints[JointType.HipRight].X - jointPoints[JointType.KneeRight].X) / thighRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                thighRightAngle = 180 - Math.Asin((jointPoints[JointType.HipRight].X - jointPoints[JointType.KneeRight].X) / thighRightLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.KneeLeft].Y <= jointPoints[JointType.AnkleLeft].Y)
                            {
                                calfLeftAngle = Math.Asin((jointPoints[JointType.KneeLeft].X - jointPoints[JointType.AnkleLeft].X) / calfLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                calfLeftAngle = 180 - Math.Asin((jointPoints[JointType.KneeLeft].X - jointPoints[JointType.AnkleLeft].X) / calfLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.KneeRight].Y <= jointPoints[JointType.AnkleRight].Y)
                            {
                                calfRightAngle = Math.Asin((jointPoints[JointType.KneeRight].X - jointPoints[JointType.AnkleRight].X) / calfRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                calfRightAngle = 180 - Math.Asin((jointPoints[JointType.KneeRight].X - jointPoints[JointType.AnkleRight].X) / calfRightLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.AnkleLeft].Y <= jointPoints[JointType.FootLeft].Y)
                            {
                                footLeftAngle = Math.Asin((jointPoints[JointType.AnkleLeft].X - jointPoints[JointType.FootLeft].X) / footLeftLength) * 180 / Math.PI;
                            }
                            else
                            {
                                footLeftAngle = 180 - Math.Asin((jointPoints[JointType.AnkleLeft].X - jointPoints[JointType.FootLeft].X) / footLeftLength) * 180 / Math.PI;
                            }

                            if (jointPoints[JointType.AnkleRight].Y <= jointPoints[JointType.FootRight].Y)
                            {
                                footRightAngle = Math.Asin((jointPoints[JointType.AnkleRight].X - jointPoints[JointType.FootRight].X) / footRightLength) * 180 / Math.PI;
                            }
                            else
                            {
                                footRightAngle = 180 - Math.Asin((jointPoints[JointType.AnkleRight].X - jointPoints[JointType.FootRight].X) / footRightLength) * 180 / Math.PI;
                            }

                            FrameEdges clippedEdges = body.ClippedEdges;

                            if (!clippedEdges.HasFlag(FrameEdges.Left) && !clippedEdges.HasFlag(FrameEdges.Right) && body.TrackingId != bodyId[0] && body.TrackingId != bodyId[1] && body.TrackingId != bodyId[2] && body.TrackingId != bodyId[3] && body.TrackingId != bodyId[4] && body.TrackingId != bodyId[5])
                            {
                                if (!wearing[0] && jointPoints[JointType.HandLeft].X > jointPoints[JointType.ShoulderRight].X && jointPoints[JointType.HandRight].X < jointPoints[JointType.ShoulderLeft].X)
                                {
                                    bodyId[0] = body.TrackingId;
                                    wearing[0] = true;

                                    System.Windows.Controls.Panel.SetZIndex(Puppet1, zIndex);
                                    System.Windows.Controls.Panel.SetZIndex(Foreground, zIndex + 1);
                                    zIndex++;

                                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                                }
                                else if  (!wearing[1] && jointPoints[JointType.ElbowLeft].Y < jointPoints[JointType.Head].Y && jointPoints[JointType.ElbowRight].Y < jointPoints[JointType.Head].Y)
                                {
                                    bodyId[1] = body.TrackingId;
                                    wearing[1] = true;

                                    System.Windows.Controls.Panel.SetZIndex(Puppet2, zIndex);
                                    System.Windows.Controls.Panel.SetZIndex(Foreground, zIndex + 1);
                                    zIndex++;

                                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                                }
                                else if (!wearing[2] && jointPoints[JointType.ElbowLeft].Y > jointPoints[JointType.SpineBase].Y && jointPoints[JointType.ElbowRight].Y > jointPoints[JointType.SpineBase].Y)
                                {
                                    bodyId[2] = body.TrackingId;
                                    wearing[2] = true;

                                    System.Windows.Controls.Panel.SetZIndex(Puppet3, zIndex);
                                    System.Windows.Controls.Panel.SetZIndex(Foreground, zIndex + 1);
                                    zIndex++;

                                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                                }
                                else if (!wearing[3] && jointPoints[JointType.KneeLeft].Y < jointPoints[JointType.HipLeft].Y)
                                {
                                    bodyId[3] = body.TrackingId;
                                    wearing[3] = true;

                                    System.Windows.Controls.Panel.SetZIndex(Puppet4, zIndex);
                                    System.Windows.Controls.Panel.SetZIndex(Foreground, zIndex + 1);
                                    zIndex++;

                                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                                }
                                else if (!wearing[4] && jointPoints[JointType.KneeRight].Y < jointPoints[JointType.HipRight].Y)
                                {
                                    bodyId[4] = body.TrackingId;
                                    wearing[4] = true;

                                    System.Windows.Controls.Panel.SetZIndex(Puppet5, zIndex);
                                    System.Windows.Controls.Panel.SetZIndex(Foreground, zIndex + 1);
                                    zIndex++;

                                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                                }
                                else if (!wearing[5] && jointPoints[JointType.HandLeft].X < jointPoints[JointType.Head].X && jointPoints[JointType.HandRight].X < jointPoints[JointType.HandLeft].X)
                                {
                                    bodyId[5] = body.TrackingId;
                                    wearing[5] = true;

                                    System.Windows.Controls.Panel.SetZIndex(Puppet6, zIndex);
                                    System.Windows.Controls.Panel.SetZIndex(Foreground, zIndex + 1);
                                    zIndex++;

                                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transform.mp3");
                                }
                            if (wearing[0])
                            {
                                puppetid = 0;
                            }
                            else if (wearing[1])
                            {
                                puppetid = 1;
                            }
                            else if (wearing[2])
                            {
                                puppetid = 2;
                            }
                            else if (wearing[3])
                            {
                                puppetid = 3;
                            }
                            else if (wearing[4])
                            {
                                puppetid = 4;
                            }
                            else if (wearing[5])
                            {
                                puppetid = 5;
                            }
                        }
                        if (jointPoints[JointType.HandLeft].X > jointPoints[JointType.HandRight].X && jointPoints[JointType.HandLeft].Y < jointPoints[JointType.Head].Y && jointPoints[JointType.HandRight].Y < jointPoints[JointType.Head].Y && jointPoints[JointType.KneeRight].Y < jointPoints[JointType.HipRight].Y)
                        {
                            if (changebg == 0)
                            {
                                changeSceneDelegate.Invoke(@"/Images/Background/Dusk.jpg", "");
                                changebg++;
                            }
                            else if (changebg == 1)
                            {
                                changeSceneDelegate.Invoke(@"/Images/Background/Forest.jpg", "");
                                changebg++;
                            }
                            else if (changebg == 2)
                            {
                                changeSceneDelegate.Invoke(@"/Images/Background/Restaurant.jpg", "");
                                changebg++;
                            }
                            else if (changebg == 3)
                            {
                                changeSceneDelegate.Invoke(@"/Images/Background/Library.jpg", "");
                                changebg++;
                            }
                            else if (changebg == 4)
                            {
                                changeSceneDelegate.Invoke(@"/Images/Background/Screen.jpg", "");
                                changebg = 0;
                            }
                        }

                        if (body.TrackingId == bodyId[0])
                            {
                                // 影像尺寸（長寬必須等比例縮放）

                                if (Double.IsInfinity(faceLength) || Double.IsInfinity(shoulderLeftLength) ||
                                    Double.IsInfinity(shoulderRightLength) || Double.IsInfinity(upperArmLeftLength) ||
                                    Double.IsInfinity(upperArmRightLength) || Double.IsInfinity(lowerArmLeftLength) ||
                                    Double.IsInfinity(lowerArmRightLength) || Double.IsInfinity(handLeftLength) ||
                                    Double.IsInfinity(handRightLength) || Double.IsInfinity(upperBodyLength) ||
                                    Double.IsInfinity(lowerBodyLength) || Double.IsInfinity(thighLeftLength) ||
                                    Double.IsInfinity(thighRightLength) || Double.IsInfinity(calfLeftLength) ||
                                    Double.IsInfinity(calfRightLength) || Double.IsInfinity(footLeftLength) || Double.IsInfinity(footRightLength))
                                {
                                    Console.WriteLine("出現無限大！");
                                }
                                else
                                {
                                    this.DrawHandLeft(body.HandLeftState, puppetid, faceLength, handLeftAngle, jointPoints[JointType.HandLeft]);
                                    this.DrawHandRight(body.HandRightState, puppetid, faceLength, handRightAngle, jointPoints[JointType.HandRight]);

                                    Face.Height = faceLength * 2.5;
                                    Face.Width = Face.ActualWidth * faceLength / Face.ActualHeight * 2.5;
                                    Smile.Height = faceLength * 2.5;
                                    Smile.Width = Smile.ActualWidth * faceLength / Smile.ActualHeight * 2.5;

                                    ShoulderLeft.Height = shoulderLeftLength * 2;
                                    ShoulderLeft.Width = ShoulderLeft.ActualWidth * shoulderLeftLength / ShoulderLeft.ActualHeight * 2;
                                    ShoulderRight.Height = shoulderRightLength * 2;
                                    ShoulderRight.Width = ShoulderRight.ActualWidth * shoulderRightLength / ShoulderRight.ActualHeight * 2;

                                    UpperArmLeft.Height = upperArmLeftLength * 1.5;
                                    UpperArmLeft.Width = UpperArmLeft.ActualWidth * upperArmLeftLength / UpperArmLeft.ActualHeight * 1.5;
                                    UpperArmRight.Height = upperArmRightLength * 1.5;
                                    UpperArmRight.Width = UpperArmRight.ActualWidth * upperArmRightLength / UpperArmRight.ActualHeight * 1.5;

                                    LowerArmLeft.Height = lowerArmLeftLength * 1.5;
                                    LowerArmLeft.Width = LowerArmLeft.ActualWidth * lowerArmLeftLength / LowerArmLeft.ActualHeight * 1.5;
                                    LowerArmRight.Height = lowerArmRightLength * 1.5;
                                    LowerArmRight.Width = LowerArmRight.ActualWidth * lowerArmRightLength / LowerArmRight.ActualHeight * 1.5;

                                    HandLeft.Height = lowerArmLeftLength * 1.5;
                                    HandLeft.Width = HandLeft.ActualWidth * lowerArmLeftLength / HandLeft.ActualHeight * 1.5;
                                    HandRight.Height = lowerArmRightLength * 1.5;
                                    HandRight.Width = HandRight.ActualWidth * lowerArmRightLength / HandRight.ActualHeight * 1.5;

                                    UpperBody.Height = upperBodyLength * 2;
                                    UpperBody.Width = UpperBody.ActualWidth * upperBodyLength / UpperBody.ActualHeight * 2;
                                    LowerBody.Height = lowerBodyLength * 1.2;
                                    LowerBody.Width = LowerBody.ActualWidth * lowerBodyLength / LowerBody.ActualHeight * 1.2;

                                    ThighLeft.Height = thighLeftLength * 1.5;
                                    ThighLeft.Width = ThighLeft.ActualWidth * thighLeftLength / ThighLeft.ActualHeight * 1.5;
                                    ThighRight.Height = thighRightLength * 1.5;
                                    ThighRight.Width = ThighRight.ActualWidth * thighRightLength / ThighRight.ActualHeight * 1.5;

                                    CalfLeft.Height = calfLeftLength;
                                    CalfLeft.Width = CalfLeft.ActualWidth * calfLeftLength / CalfLeft.ActualHeight;
                                    CalfRight.Height = calfRightLength;
                                    CalfRight.Width = CalfRight.ActualWidth * calfRightLength / CalfRight.ActualHeight;

                                    FootLeft.Height = footLeftLength * 2.5;
                                    FootLeft.Width = FootLeft.ActualWidth * footLeftLength / FootLeft.ActualHeight * 2.5;
                                    FootRight.Height = footRightLength * 2.5;
                                    FootRight.Width = FootRight.ActualWidth * footRightLength / FootRight.ActualHeight * 2.5;

                                    // 影像旋轉

                                    RotateTransform faceRotate = new RotateTransform(faceAngle, Face.Width / 2, Face.Height / 2);
                                    Face.RenderTransform = faceRotate;
                                    Smile.RenderTransform = faceRotate;

                                    RotateTransform shoulderLeftRotate = new RotateTransform(shoulderLeftAngle, ShoulderLeft.Width / 2, ShoulderLeft.Height / 2);
                                    ShoulderLeft.RenderTransform = shoulderLeftRotate;

                                    RotateTransform shoulderRightRotate = new RotateTransform(shoulderRightAngle, ShoulderRight.Width / 2, ShoulderRight.Height / 2);
                                    ShoulderRight.RenderTransform = shoulderRightRotate;

                                    RotateTransform upperArmLeftRotate = new RotateTransform(upperArmLeftAngle, UpperArmLeft.Width / 2, UpperArmLeft.Height / 2);
                                    UpperArmLeft.RenderTransform = upperArmLeftRotate;

                                    RotateTransform upperArmRightRotate = new RotateTransform(upperArmRightAngle, UpperArmRight.Width / 2, UpperArmRight.Height / 2);
                                    UpperArmRight.RenderTransform = upperArmRightRotate;

                                    RotateTransform lowerArmLeftRotate = new RotateTransform(lowerArmLeftAngle, LowerArmLeft.Width / 2, LowerArmLeft.Height / 2);
                                    LowerArmLeft.RenderTransform = lowerArmLeftRotate;

                                    RotateTransform lowerArmRightRotate = new RotateTransform(lowerArmRightAngle, LowerArmRight.Width / 2, LowerArmRight.Height / 2);
                                    LowerArmRight.RenderTransform = lowerArmRightRotate;

                                    RotateTransform handLeftRotate = new RotateTransform(handLeftAngle, HandLeft.Width / 2, HandLeft.Height / 2);
                                    HandLeft.RenderTransform = handLeftRotate;

                                    RotateTransform handRightRotate = new RotateTransform(handRightAngle, HandRight.Width / 2, HandRight.Height / 2);
                                    HandRight.RenderTransform = handRightRotate;

                                    RotateTransform upperBodyRotate = new RotateTransform(upperBodyAngle, UpperBody.Width / 2, UpperBody.Height / 2);
                                    UpperBody.RenderTransform = upperBodyRotate;

                                    RotateTransform lowerBodyRotate = new RotateTransform(lowerBodyAngle, LowerBody.Width / 2, LowerBody.Height / 2);
                                    LowerBody.RenderTransform = lowerBodyRotate;

                                    RotateTransform thighLeftRotate = new RotateTransform(thighLeftAngle, ThighLeft.Width / 2, ThighLeft.Height / 2);
                                    ThighLeft.RenderTransform = thighLeftRotate;

                                    RotateTransform thighRightRotate = new RotateTransform(thighRightAngle, ThighRight.Width / 2, ThighRight.Height / 2);
                                    ThighRight.RenderTransform = thighRightRotate;

                                    RotateTransform calfLeftRotate = new RotateTransform(calfLeftAngle, CalfLeft.Width / 2, CalfLeft.Height / 2);
                                    CalfLeft.RenderTransform = calfLeftRotate;

                                    RotateTransform calfRightRotate = new RotateTransform(calfRightAngle, CalfRight.Width / 2, CalfRight.Height / 2);
                                    CalfRight.RenderTransform = calfRightRotate;

                                    RotateTransform footLeftRotate = new RotateTransform(footLeftAngle, FootLeft.Width / 2, FootLeft.Height / 2);
                                    FootLeft.RenderTransform = footLeftRotate;

                                    RotateTransform footRightRotate = new RotateTransform(footRightAngle, FootRight.Width / 2, FootRight.Height / 2);
                                    FootRight.RenderTransform = footRightRotate;

                                    // 將影像放到指定座標

                                    Canvas.SetLeft(Face, jointPoints[JointType.Head].X - (Face.Width / 2));
                                    Canvas.SetTop(Face, jointPoints[JointType.Head].Y - (Face.Height / 2));
                                    Canvas.SetLeft(Smile, jointPoints[JointType.Head].X - (Smile.Width / 2));
                                    Canvas.SetTop(Smile, jointPoints[JointType.Head].Y - (Smile.Height / 2));

                                    Canvas.SetLeft(ShoulderLeft, jointPoints[JointType.ShoulderLeft].X - (ShoulderLeft.Width / 2));
                                    Canvas.SetTop(ShoulderLeft, jointPoints[JointType.ShoulderLeft].Y - (ShoulderLeft.Height / 2));
                                    Canvas.SetLeft(ShoulderRight, jointPoints[JointType.ShoulderRight].X - (ShoulderRight.Width / 2));
                                    Canvas.SetTop(ShoulderRight, jointPoints[JointType.ShoulderRight].Y - (ShoulderRight.Height / 2));

                                    Canvas.SetLeft(UpperArmLeft, (jointPoints[JointType.ShoulderLeft].X + jointPoints[JointType.ElbowLeft].X) / 2 - (UpperArmLeft.Width / 2));
                                    Canvas.SetTop(UpperArmLeft, (jointPoints[JointType.ShoulderLeft].Y + jointPoints[JointType.ElbowLeft].Y) / 2 - (UpperArmLeft.Height / 2));
                                    Canvas.SetLeft(UpperArmRight, (jointPoints[JointType.ShoulderRight].X + jointPoints[JointType.ElbowRight].X) / 2 - (UpperArmRight.Width / 2));
                                    Canvas.SetTop(UpperArmRight, (jointPoints[JointType.ShoulderRight].Y + jointPoints[JointType.ElbowRight].Y) / 2 - (UpperArmRight.Height / 2));

                                    Canvas.SetLeft(LowerArmLeft, (jointPoints[JointType.ElbowLeft].X + jointPoints[JointType.WristLeft].X) / 2 - (LowerArmLeft.Width / 2));
                                    Canvas.SetTop(LowerArmLeft, (jointPoints[JointType.ElbowLeft].Y + jointPoints[JointType.WristLeft].Y) / 2 - (LowerArmLeft.Height / 2));

                                    Canvas.SetLeft(LowerArmRight, (jointPoints[JointType.ElbowRight].X + jointPoints[JointType.WristRight].X) / 2 - (LowerArmRight.Width / 2));
                                    Canvas.SetTop(LowerArmRight, (jointPoints[JointType.ElbowRight].Y + jointPoints[JointType.WristRight].Y) / 2 - (LowerArmRight.Height / 2));

                                    Canvas.SetLeft(HandLeft, jointPoints[JointType.HandLeft].X - (HandLeft.Width / 2));
                                    Canvas.SetTop(HandLeft, jointPoints[JointType.HandLeft].Y - (HandLeft.Height / 2));

                                    Canvas.SetLeft(HandRight, jointPoints[JointType.HandRight].X - (HandRight.Width / 2));
                                    Canvas.SetTop(HandRight, jointPoints[JointType.HandRight].Y - (HandRight.Height / 2));

                                    Canvas.SetLeft(UpperBody, jointPoints[JointType.SpineMid].X - (UpperBody.Width / 2));
                                    Canvas.SetTop(UpperBody, jointPoints[JointType.SpineMid].Y - (UpperBody.Height / 2));
                                    Canvas.SetLeft(LowerBody, jointPoints[JointType.SpineBase].X - (LowerBody.Width / 2));
                                    Canvas.SetTop(LowerBody, jointPoints[JointType.SpineBase].Y + 10 - (LowerBody.Height / 2));

                                    Canvas.SetLeft(ThighLeft, (jointPoints[JointType.HipLeft].X + jointPoints[JointType.KneeLeft].X) / 2 - (ThighLeft.Width / 2));
                                    Canvas.SetTop(ThighLeft, (jointPoints[JointType.HipLeft].Y + jointPoints[JointType.KneeLeft].Y) / 2 - (ThighLeft.Height / 2));
                                    Canvas.SetLeft(ThighRight, (jointPoints[JointType.HipRight].X + jointPoints[JointType.KneeRight].X) / 2 - (ThighRight.Width / 2));
                                    Canvas.SetTop(ThighRight, (jointPoints[JointType.HipRight].Y + jointPoints[JointType.KneeRight].Y) / 2 - (ThighRight.Height / 2));

                                    Canvas.SetLeft(CalfLeft, (jointPoints[JointType.KneeLeft].X + jointPoints[JointType.AnkleLeft].X) / 2 - (CalfLeft.Width / 2));
                                    Canvas.SetTop(CalfLeft, (jointPoints[JointType.KneeLeft].Y + jointPoints[JointType.AnkleLeft].Y) / 2 - (CalfLeft.Height / 2));
                                    Canvas.SetLeft(CalfRight, (jointPoints[JointType.KneeRight].X + jointPoints[JointType.AnkleRight].X) / 2 - (CalfRight.Width / 2));
                                    Canvas.SetTop(CalfRight, (jointPoints[JointType.KneeRight].Y + jointPoints[JointType.AnkleRight].Y) / 2 - (CalfRight.Height / 2));

                                    Canvas.SetLeft(FootLeft, jointPoints[JointType.FootLeft].X - (FootLeft.Width / 2));
                                    Canvas.SetTop(FootLeft, jointPoints[JointType.FootLeft].Y - (FootLeft.Height / 2));
                                    Canvas.SetLeft(FootRight, jointPoints[JointType.FootRight].X - (FootRight.Width / 2));
                                    Canvas.SetTop(FootRight, jointPoints[JointType.FootRight].Y - (FootRight.Height / 2));
                                }
                            }
                            else if (body.TrackingId == bodyId[1])
                            {
                                // 影像尺寸（長寬必須等比例縮放）

                                if (Double.IsInfinity(faceLength) || Double.IsInfinity(shoulderLeftLength) ||
                                    Double.IsInfinity(shoulderRightLength) || Double.IsInfinity(upperArmLeftLength) ||
                                    Double.IsInfinity(upperArmRightLength) || Double.IsInfinity(lowerArmLeftLength) ||
                                    Double.IsInfinity(lowerArmRightLength) || Double.IsInfinity(handLeftLength) ||
                                    Double.IsInfinity(handRightLength) || Double.IsInfinity(upperBodyLength) ||
                                    Double.IsInfinity(lowerBodyLength) || Double.IsInfinity(thighLeftLength) ||
                                    Double.IsInfinity(thighRightLength) || Double.IsInfinity(calfLeftLength) ||
                                    Double.IsInfinity(calfRightLength) || Double.IsInfinity(footLeftLength) || Double.IsInfinity(footRightLength))
                                {
                                    Console.WriteLine("出現無限大！");
                                }
                                else
                                {
                                    this.DrawHandLeft(body.HandLeftState, puppetid, faceLength, handLeftAngle, jointPoints[JointType.HandLeft]);
                                    this.DrawHandRight(body.HandRightState, puppetid, faceLength, handRightAngle, jointPoints[JointType.HandRight]);

                                    Face2.Height = faceLength * 2.5;
                                    Face2.Width = Face2.ActualWidth * faceLength / Face2.ActualHeight * 2.5;
                                    Facechange.Height = faceLength * 2.5;
                                    Facechange.Width = Facechange.ActualWidth * faceLength / Facechange.ActualHeight * 2.5;

                                    ShoulderLeft2.Height = shoulderLeftLength * 2;
                                    ShoulderLeft2.Width = ShoulderLeft2.ActualWidth * shoulderLeftLength / ShoulderLeft2.ActualHeight * 2;
                                    ShoulderRight2.Height = shoulderRightLength * 2;
                                    ShoulderRight2.Width = ShoulderRight2.ActualWidth * shoulderRightLength / ShoulderRight2.ActualHeight * 2;

                                    UpperArmLeft2.Height = upperArmLeftLength * 1.5;
                                    UpperArmLeft2.Width = UpperArmLeft2.ActualWidth * upperArmLeftLength / UpperArmLeft2.ActualHeight * 1.5;
                                    UpperArmRight2.Height = upperArmRightLength * 1.5;
                                    UpperArmRight2.Width = UpperArmRight2.ActualWidth * upperArmRightLength / UpperArmRight2.ActualHeight * 1.5;

                                    LowerArmLeft2.Height = lowerArmLeftLength * 1.5;
                                    LowerArmLeft2.Width = LowerArmLeft2.ActualWidth * lowerArmLeftLength / LowerArmLeft2.ActualHeight * 1.5;
                                    LowerArmRight2.Height = lowerArmRightLength * 1.5;
                                    LowerArmRight2.Width = LowerArmRight2.ActualWidth * lowerArmRightLength / LowerArmRight2.ActualHeight * 1.5;

                                    HandLeft2.Height = lowerArmLeftLength * 1.5;
                                    HandLeft2.Width = HandLeft2.ActualWidth * lowerArmLeftLength / HandLeft2.ActualHeight * 1.5;
                                    HandRight2.Height = lowerArmRightLength * 1.5;
                                    HandRight2.Width = HandRight2.ActualWidth * lowerArmRightLength / HandRight2.ActualHeight * 1.5;

                                    UpperBody2.Height = upperBodyLength * 2;
                                    UpperBody2.Width = UpperBody2.ActualWidth * upperBodyLength / UpperBody2.ActualHeight * 2;
                                    LowerBody2.Height = lowerBodyLength * 1.2;
                                    LowerBody2.Width = LowerBody2.ActualWidth * lowerBodyLength / LowerBody2.ActualHeight * 1.2;

                                    ThighLeft2.Height = thighLeftLength * 1.5;
                                    ThighLeft2.Width = ThighLeft2.ActualWidth * thighLeftLength / ThighLeft2.ActualHeight * 1.5;
                                    ThighRight2.Height = thighRightLength * 1.5;
                                    ThighRight2.Width = ThighRight2.ActualWidth * thighRightLength / ThighRight2.ActualHeight * 1.5;

                                    CalfLeft2.Height = calfLeftLength;
                                    CalfLeft2.Width = CalfLeft2.ActualWidth * calfLeftLength / CalfLeft2.ActualHeight;
                                    CalfRight2.Height = calfRightLength;
                                    CalfRight2.Width = CalfRight2.ActualWidth * calfRightLength / CalfRight2.ActualHeight;

                                    FootLeft2.Height = footLeftLength * 2.5;
                                    FootLeft2.Width = FootLeft2.ActualWidth * footLeftLength / FootLeft2.ActualHeight * 2.5;
                                    FootRight2.Height = footRightLength * 2.5;
                                    FootRight2.Width = FootRight2.ActualWidth * footRightLength / FootRight2.ActualHeight * 2.5;

                                    // 影像旋轉

                                    RotateTransform faceRotate = new RotateTransform(faceAngle, Face2.Width / 2, Face2.Height / 2);
                                    Face2.RenderTransform = faceRotate;
                                    Facechange.RenderTransform = faceRotate;

                                RotateTransform shoulderLeftRotate = new RotateTransform(shoulderLeftAngle, ShoulderLeft2.Width / 2, ShoulderLeft2.Height / 2);
                                    ShoulderLeft2.RenderTransform = shoulderLeftRotate;

                                    RotateTransform shoulderRightRotate = new RotateTransform(shoulderRightAngle, ShoulderRight2.Width / 2, ShoulderRight2.Height / 2);
                                    ShoulderRight2.RenderTransform = shoulderRightRotate;

                                    RotateTransform upperArmLeftRotate = new RotateTransform(upperArmLeftAngle, UpperArmLeft2.Width / 2, UpperArmLeft2.Height / 2);
                                    UpperArmLeft2.RenderTransform = upperArmLeftRotate;

                                    RotateTransform upperArmRightRotate = new RotateTransform(upperArmRightAngle, UpperArmRight2.Width / 2, UpperArmRight2.Height / 2);
                                    UpperArmRight2.RenderTransform = upperArmRightRotate;

                                    RotateTransform lowerArmLeftRotate = new RotateTransform(lowerArmLeftAngle, LowerArmLeft2.Width / 2, LowerArmLeft2.Height / 2);
                                    LowerArmLeft2.RenderTransform = lowerArmLeftRotate;

                                    RotateTransform lowerArmRightRotate = new RotateTransform(lowerArmRightAngle, LowerArmRight2.Width / 2, LowerArmRight2.Height / 2);
                                    LowerArmRight2.RenderTransform = lowerArmRightRotate;

                                    RotateTransform handLeftRotate = new RotateTransform(handLeftAngle, HandLeft2.Width / 2, HandLeft2.Height / 2);
                                    HandLeft2.RenderTransform = handLeftRotate;

                                    RotateTransform handRightRotate = new RotateTransform(handRightAngle, HandRight2.Width / 2, HandRight2.Height / 2);
                                    HandRight2.RenderTransform = handRightRotate;

                                    RotateTransform upperBodyRotate = new RotateTransform(upperBodyAngle, UpperBody2.Width / 2, UpperBody2.Height / 2);
                                    UpperBody2.RenderTransform = upperBodyRotate;

                                    RotateTransform lowerBodyRotate = new RotateTransform(lowerBodyAngle, LowerBody2.Width / 2, LowerBody2.Height / 2);
                                    LowerBody2.RenderTransform = lowerBodyRotate;

                                    RotateTransform thighLeftRotate = new RotateTransform(thighLeftAngle, ThighLeft2.Width / 2, ThighLeft2.Height / 2);
                                    ThighLeft2.RenderTransform = thighLeftRotate;

                                    RotateTransform thighRightRotate = new RotateTransform(thighRightAngle, ThighRight2.Width / 2, ThighRight2.Height / 2);
                                    ThighRight2.RenderTransform = thighRightRotate;

                                    RotateTransform calfLeftRotate = new RotateTransform(calfLeftAngle, CalfLeft2.Width / 2, CalfLeft2.Height / 2);
                                    CalfLeft2.RenderTransform = calfLeftRotate;

                                    RotateTransform calfRightRotate = new RotateTransform(calfRightAngle, CalfRight2.Width / 2, CalfRight2.Height / 2);
                                    CalfRight2.RenderTransform = calfRightRotate;

                                    RotateTransform footLeftRotate = new RotateTransform(footLeftAngle, FootLeft2.Width / 2, FootLeft2.Height / 2);
                                    FootLeft2.RenderTransform = footLeftRotate;

                                    RotateTransform footRightRotate = new RotateTransform(footRightAngle, FootRight2.Width / 2, FootRight2.Height / 2);
                                    FootRight2.RenderTransform = footRightRotate;

                                    // 將影像放到指定座標

                                    Canvas.SetLeft(Face2, jointPoints[JointType.Head].X - (Face2.Width / 2));
                                    Canvas.SetTop(Face2, jointPoints[JointType.Head].Y - (Face2.Height / 2));
                                    Canvas.SetLeft(Facechange, jointPoints[JointType.Head].X - (Facechange.Width / 2));
                                    Canvas.SetTop(Facechange, jointPoints[JointType.Head].Y - (Facechange.Height / 2));

                                    Canvas.SetLeft(ShoulderLeft2, jointPoints[JointType.ShoulderLeft].X - (ShoulderLeft2.Width / 2));
                                    Canvas.SetTop(ShoulderLeft2, jointPoints[JointType.ShoulderLeft].Y - (ShoulderLeft2.Height / 2));
                                    Canvas.SetLeft(ShoulderRight2, jointPoints[JointType.ShoulderRight].X - (ShoulderRight2.Width / 2));
                                    Canvas.SetTop(ShoulderRight2, jointPoints[JointType.ShoulderRight].Y - (ShoulderRight2.Height / 2));

                                    Canvas.SetLeft(UpperArmLeft2, (jointPoints[JointType.ShoulderLeft].X + jointPoints[JointType.ElbowLeft].X) / 2 - (UpperArmLeft2.Width / 2));
                                    Canvas.SetTop(UpperArmLeft2, (jointPoints[JointType.ShoulderLeft].Y + jointPoints[JointType.ElbowLeft].Y) / 2 - (UpperArmLeft2.Height / 2));
                                    Canvas.SetLeft(UpperArmRight2, (jointPoints[JointType.ShoulderRight].X + jointPoints[JointType.ElbowRight].X) / 2 - (UpperArmRight2.Width / 2));
                                    Canvas.SetTop(UpperArmRight2, (jointPoints[JointType.ShoulderRight].Y + jointPoints[JointType.ElbowRight].Y) / 2 - (UpperArmRight2.Height / 2));

                                    Canvas.SetLeft(LowerArmLeft2, (jointPoints[JointType.ElbowLeft].X + jointPoints[JointType.WristLeft].X) / 2 - (LowerArmLeft2.Width / 2));
                                    Canvas.SetTop(LowerArmLeft2, (jointPoints[JointType.ElbowLeft].Y + jointPoints[JointType.WristLeft].Y) / 2 - (LowerArmLeft2.Height / 2));

                                    Canvas.SetLeft(LowerArmRight2, (jointPoints[JointType.ElbowRight].X + jointPoints[JointType.WristRight].X) / 2 - (LowerArmRight2.Width / 2));
                                    Canvas.SetTop(LowerArmRight2, (jointPoints[JointType.ElbowRight].Y + jointPoints[JointType.WristRight].Y) / 2 - (LowerArmRight2.Height / 2));

                                    Canvas.SetLeft(HandLeft2, jointPoints[JointType.HandLeft].X - (HandLeft2.Width / 2));
                                    Canvas.SetTop(HandLeft2, jointPoints[JointType.HandLeft].Y - (HandLeft2.Height / 2));

                                    Canvas.SetLeft(HandRight2, jointPoints[JointType.HandRight].X - (HandRight2.Width / 2));
                                    Canvas.SetTop(HandRight2, jointPoints[JointType.HandRight].Y - (HandRight2.Height / 2));

                                    Canvas.SetLeft(UpperBody2, jointPoints[JointType.SpineMid].X - (UpperBody2.Width / 2));
                                    Canvas.SetTop(UpperBody2, jointPoints[JointType.SpineMid].Y - (UpperBody2.Height / 2));
                                    Canvas.SetLeft(LowerBody2, jointPoints[JointType.SpineBase].X - (LowerBody2.Width / 2));
                                    Canvas.SetTop(LowerBody2, jointPoints[JointType.SpineBase].Y + 10 - (LowerBody2.Height / 2));

                                    Canvas.SetLeft(ThighLeft2, (jointPoints[JointType.HipLeft].X + jointPoints[JointType.KneeLeft].X) / 2 - (ThighLeft2.Width / 2));
                                    Canvas.SetTop(ThighLeft2, (jointPoints[JointType.HipLeft].Y + jointPoints[JointType.KneeLeft].Y) / 2 - (ThighLeft2.Height / 2));
                                    Canvas.SetLeft(ThighRight2, (jointPoints[JointType.HipRight].X + jointPoints[JointType.KneeRight].X) / 2 - (ThighRight2.Width / 2));
                                    Canvas.SetTop(ThighRight2, (jointPoints[JointType.HipRight].Y + jointPoints[JointType.KneeRight].Y) / 2 - (ThighRight2.Height / 2));

                                    Canvas.SetLeft(CalfLeft2, (jointPoints[JointType.KneeLeft].X + jointPoints[JointType.AnkleLeft].X) / 2 - (CalfLeft2.Width / 2));
                                    Canvas.SetTop(CalfLeft2, (jointPoints[JointType.KneeLeft].Y + jointPoints[JointType.AnkleLeft].Y) / 2 - (CalfLeft2.Height / 2));
                                    Canvas.SetLeft(CalfRight2, (jointPoints[JointType.KneeRight].X + jointPoints[JointType.AnkleRight].X) / 2 - (CalfRight2.Width / 2));
                                    Canvas.SetTop(CalfRight2, (jointPoints[JointType.KneeRight].Y + jointPoints[JointType.AnkleRight].Y) / 2 - (CalfRight2.Height / 2));

                                    Canvas.SetLeft(FootLeft2, jointPoints[JointType.FootLeft].X - (FootLeft2.Width / 2));
                                    Canvas.SetTop(FootLeft2, jointPoints[JointType.FootLeft].Y - (FootLeft2.Height / 2));
                                    Canvas.SetLeft(FootRight2, jointPoints[JointType.FootRight].X - (FootRight2.Width / 2));
                                    Canvas.SetTop(FootRight2, jointPoints[JointType.FootRight].Y - (FootRight2.Height / 2));
                                }
                            }
                            else if (body.TrackingId == bodyId[2])
                            {
                                // 影像尺寸（長寬必須等比例縮放）

                                if (Double.IsInfinity(faceLength) || Double.IsInfinity(shoulderLeftLength) ||
                                    Double.IsInfinity(shoulderRightLength) || Double.IsInfinity(upperArmLeftLength) ||
                                    Double.IsInfinity(upperArmRightLength) || Double.IsInfinity(lowerArmLeftLength) ||
                                    Double.IsInfinity(lowerArmRightLength) || Double.IsInfinity(handLeftLength) ||
                                    Double.IsInfinity(handRightLength) || Double.IsInfinity(upperBodyLength) ||
                                    Double.IsInfinity(lowerBodyLength) || Double.IsInfinity(thighLeftLength) ||
                                    Double.IsInfinity(thighRightLength) || Double.IsInfinity(calfLeftLength) ||
                                    Double.IsInfinity(calfRightLength) || Double.IsInfinity(footLeftLength) || Double.IsInfinity(footRightLength))
                                {
                                    Console.WriteLine("出現無限大！");
                                }
                                else
                                {
                                    this.DrawHandLeft(body.HandLeftState, puppetid, faceLength, handLeftAngle, jointPoints[JointType.HandLeft]);
                                    this.DrawHandRight(body.HandRightState, puppetid, faceLength, handRightAngle, jointPoints[JointType.HandRight]);

                                    Face3.Height = faceLength * 2.5;
                                    Face3.Width = Face3.ActualWidth * faceLength / Face3.ActualHeight * 2.5;
                                    Facechange2.Height = faceLength * 2.5;
                                    Facechange2.Width = Facechange2.ActualWidth * faceLength / Facechange2.ActualHeight * 2.5;

                                    ShoulderLeft3.Height = shoulderLeftLength * 2;
                                    ShoulderLeft3.Width = ShoulderLeft3.ActualWidth * shoulderLeftLength / ShoulderLeft3.ActualHeight * 2;
                                    ShoulderRight3.Height = shoulderRightLength * 2;
                                    ShoulderRight3.Width = ShoulderRight3.ActualWidth * shoulderRightLength / ShoulderRight3.ActualHeight * 2;

                                    UpperArmLeft3.Height = upperArmLeftLength * 1.5;
                                    UpperArmLeft3.Width = UpperArmLeft3.ActualWidth * upperArmLeftLength / UpperArmLeft3.ActualHeight * 1.5;
                                    UpperArmRight3.Height = upperArmRightLength * 1.5;
                                    UpperArmRight3.Width = UpperArmRight3.ActualWidth * upperArmRightLength / UpperArmRight3.ActualHeight * 1.5;

                                    LowerArmLeft3.Height = lowerArmLeftLength * 1.5;
                                    LowerArmLeft3.Width = LowerArmLeft3.ActualWidth * lowerArmLeftLength / LowerArmLeft3.ActualHeight * 1.5;
                                    LowerArmRight3.Height = lowerArmRightLength * 1.5;
                                    LowerArmRight3.Width = LowerArmRight3.ActualWidth * lowerArmRightLength / LowerArmRight3.ActualHeight * 1.5;

                                    HandLeft3.Height = lowerArmLeftLength * 1.5;
                                    HandLeft3.Width = HandLeft3.ActualWidth * lowerArmLeftLength / HandLeft3.ActualHeight * 1.5;
                                    HandRight3.Height = lowerArmRightLength * 1.5;
                                    HandRight3.Width = HandRight3.ActualWidth * lowerArmRightLength / HandRight3.ActualHeight * 1.5;

                                    UpperBody3.Height = upperBodyLength * 2;
                                    UpperBody3.Width = UpperBody3.ActualWidth * upperBodyLength / UpperBody3.ActualHeight * 2;
                                    LowerBody3.Height = lowerBodyLength * 1.2;
                                    LowerBody3.Width = LowerBody3.ActualWidth * lowerBodyLength / LowerBody3.ActualHeight * 1.2;

                                    ThighLeft3.Height = thighLeftLength * 1.5;
                                    ThighLeft3.Width = ThighLeft3.ActualWidth * thighLeftLength / ThighLeft3.ActualHeight * 1.5;
                                    ThighRight3.Height = thighRightLength * 1.5;
                                    ThighRight3.Width = ThighRight3.ActualWidth * thighRightLength / ThighRight3.ActualHeight * 1.5;

                                    CalfLeft3.Height = calfLeftLength;
                                    CalfLeft3.Width = CalfLeft3.ActualWidth * calfLeftLength / CalfLeft3.ActualHeight;
                                    CalfRight3.Height = calfRightLength;
                                    CalfRight3.Width = CalfRight3.ActualWidth * calfRightLength / CalfRight3.ActualHeight;

                                    FootLeft3.Height = footLeftLength * 2.5;
                                    FootLeft3.Width = FootLeft3.ActualWidth * footLeftLength / FootLeft3.ActualHeight * 2.5;
                                    FootRight3.Height = footRightLength * 2.5;
                                    FootRight3.Width = FootRight3.ActualWidth * footRightLength / FootRight3.ActualHeight * 2.5;

                                    // 影像旋轉

                                    RotateTransform faceRotate = new RotateTransform(faceAngle, Face3.Width / 2, Face3.Height / 2);
                                    Face3.RenderTransform = faceRotate;
                                    Facechange2.RenderTransform = faceRotate;

                                    RotateTransform shoulderLeftRotate = new RotateTransform(shoulderLeftAngle, ShoulderLeft3.Width / 2, ShoulderLeft3.Height / 2);
                                    ShoulderLeft3.RenderTransform = shoulderLeftRotate;

                                    RotateTransform shoulderRightRotate = new RotateTransform(shoulderRightAngle, ShoulderRight3.Width / 2, ShoulderRight3.Height / 2);
                                    ShoulderRight3.RenderTransform = shoulderRightRotate;

                                    RotateTransform upperArmLeftRotate = new RotateTransform(upperArmLeftAngle, UpperArmLeft3.Width / 2, UpperArmLeft3.Height / 2);
                                    UpperArmLeft3.RenderTransform = upperArmLeftRotate;

                                    RotateTransform upperArmRightRotate = new RotateTransform(upperArmRightAngle, UpperArmRight3.Width / 2, UpperArmRight3.Height / 2);
                                    UpperArmRight3.RenderTransform = upperArmRightRotate;

                                    RotateTransform lowerArmLeftRotate = new RotateTransform(lowerArmLeftAngle, LowerArmLeft3.Width / 2, LowerArmLeft3.Height / 2);
                                    LowerArmLeft3.RenderTransform = lowerArmLeftRotate;

                                    RotateTransform lowerArmRightRotate = new RotateTransform(lowerArmRightAngle, LowerArmRight3.Width / 2, LowerArmRight3.Height / 2);
                                    LowerArmRight3.RenderTransform = lowerArmRightRotate;

                                    RotateTransform handLeftRotate = new RotateTransform(handLeftAngle, HandLeft3.Width / 2, HandLeft3.Height / 2);
                                    HandLeft3.RenderTransform = handLeftRotate;

                                    RotateTransform handRightRotate = new RotateTransform(handRightAngle, HandRight3.Width / 2, HandRight3.Height / 2);
                                    HandRight3.RenderTransform = handRightRotate;

                                    RotateTransform upperBodyRotate = new RotateTransform(upperBodyAngle, UpperBody3.Width / 2, UpperBody3.Height / 2);
                                    UpperBody3.RenderTransform = upperBodyRotate;

                                    RotateTransform lowerBodyRotate = new RotateTransform(lowerBodyAngle, LowerBody3.Width / 2, LowerBody3.Height / 2);
                                    LowerBody3.RenderTransform = lowerBodyRotate;

                                    RotateTransform thighLeftRotate = new RotateTransform(thighLeftAngle, ThighLeft3.Width / 2, ThighLeft3.Height / 2);
                                    ThighLeft3.RenderTransform = thighLeftRotate;

                                    RotateTransform thighRightRotate = new RotateTransform(thighRightAngle, ThighRight3.Width / 2, ThighRight3.Height / 2);
                                    ThighRight3.RenderTransform = thighRightRotate;

                                    RotateTransform calfLeftRotate = new RotateTransform(calfLeftAngle, CalfLeft3.Width / 2, CalfLeft3.Height / 2);
                                    CalfLeft3.RenderTransform = calfLeftRotate;

                                    RotateTransform calfRightRotate = new RotateTransform(calfRightAngle, CalfRight3.Width / 2, CalfRight3.Height / 2);
                                    CalfRight3.RenderTransform = calfRightRotate;

                                    RotateTransform footLeftRotate = new RotateTransform(footLeftAngle, FootLeft3.Width / 2, FootLeft3.Height / 2);
                                    FootLeft3.RenderTransform = footLeftRotate;

                                    RotateTransform footRightRotate = new RotateTransform(footRightAngle, FootRight3.Width / 2, FootRight3.Height / 2);
                                    FootRight3.RenderTransform = footRightRotate;

                                    // 將影像放到指定座標

                                    Canvas.SetLeft(Face3, jointPoints[JointType.Head].X - (Face3.Width / 2));
                                    Canvas.SetTop(Face3, jointPoints[JointType.Head].Y - (Face3.Height / 2));
                                    Canvas.SetLeft(Facechange2, jointPoints[JointType.Head].X - (Facechange2.Width / 2));
                                    Canvas.SetTop(Facechange2, jointPoints[JointType.Head].Y - (Facechange2.Height / 2));

                                    Canvas.SetLeft(ShoulderLeft3, jointPoints[JointType.ShoulderLeft].X - (ShoulderLeft3.Width / 2));
                                    Canvas.SetTop(ShoulderLeft3, jointPoints[JointType.ShoulderLeft].Y - (ShoulderLeft3.Height / 2));
                                    Canvas.SetLeft(ShoulderRight3, jointPoints[JointType.ShoulderRight].X - (ShoulderRight3.Width / 2));
                                    Canvas.SetTop(ShoulderRight3, jointPoints[JointType.ShoulderRight].Y - (ShoulderRight3.Height / 2));

                                    Canvas.SetLeft(UpperArmLeft3, (jointPoints[JointType.ShoulderLeft].X + jointPoints[JointType.ElbowLeft].X) / 2 - (UpperArmLeft3.Width / 2));
                                    Canvas.SetTop(UpperArmLeft3, (jointPoints[JointType.ShoulderLeft].Y + jointPoints[JointType.ElbowLeft].Y) / 2 - (UpperArmLeft3.Height / 2));
                                    Canvas.SetLeft(UpperArmRight3, (jointPoints[JointType.ShoulderRight].X + jointPoints[JointType.ElbowRight].X) / 2 - (UpperArmRight3.Width / 2));
                                    Canvas.SetTop(UpperArmRight3, (jointPoints[JointType.ShoulderRight].Y + jointPoints[JointType.ElbowRight].Y) / 2 - (UpperArmRight3.Height / 2));

                                    Canvas.SetLeft(LowerArmLeft3, (jointPoints[JointType.ElbowLeft].X + jointPoints[JointType.WristLeft].X) / 2 - (LowerArmLeft3.Width / 2));
                                    Canvas.SetTop(LowerArmLeft3, (jointPoints[JointType.ElbowLeft].Y + jointPoints[JointType.WristLeft].Y) / 2 - (LowerArmLeft3.Height / 2));

                                    Canvas.SetLeft(LowerArmRight3, (jointPoints[JointType.ElbowRight].X + jointPoints[JointType.WristRight].X) / 2 - (LowerArmRight3.Width / 2));
                                    Canvas.SetTop(LowerArmRight3, (jointPoints[JointType.ElbowRight].Y + jointPoints[JointType.WristRight].Y) / 2 - (LowerArmRight3.Height / 2));

                                    Canvas.SetLeft(HandLeft3, jointPoints[JointType.HandLeft].X - (HandLeft3.Width / 2));
                                    Canvas.SetTop(HandLeft3, jointPoints[JointType.HandLeft].Y - (HandLeft3.Height / 2));

                                    Canvas.SetLeft(HandRight3, jointPoints[JointType.HandRight].X - (HandRight3.Width / 2));
                                    Canvas.SetTop(HandRight3, jointPoints[JointType.HandRight].Y - (HandRight3.Height / 2));

                                    Canvas.SetLeft(UpperBody3, jointPoints[JointType.SpineMid].X - (UpperBody3.Width / 2));
                                    Canvas.SetTop(UpperBody3, jointPoints[JointType.SpineMid].Y - (UpperBody3.Height / 2));
                                    Canvas.SetLeft(LowerBody3, jointPoints[JointType.SpineBase].X - (LowerBody3.Width / 2));
                                    Canvas.SetTop(LowerBody3, jointPoints[JointType.SpineBase].Y + 10 - (LowerBody3.Height / 2));

                                    Canvas.SetLeft(ThighLeft3, (jointPoints[JointType.HipLeft].X + jointPoints[JointType.KneeLeft].X) / 2 - (ThighLeft3.Width / 2));
                                    Canvas.SetTop(ThighLeft3, (jointPoints[JointType.HipLeft].Y + jointPoints[JointType.KneeLeft].Y) / 2 - (ThighLeft3.Height / 2));
                                    Canvas.SetLeft(ThighRight3, (jointPoints[JointType.HipRight].X + jointPoints[JointType.KneeRight].X) / 2 - (ThighRight3.Width / 2));
                                    Canvas.SetTop(ThighRight3, (jointPoints[JointType.HipRight].Y + jointPoints[JointType.KneeRight].Y) / 2 - (ThighRight3.Height / 2));

                                    Canvas.SetLeft(CalfLeft3, (jointPoints[JointType.KneeLeft].X + jointPoints[JointType.AnkleLeft].X) / 2 - (CalfLeft3.Width / 2));
                                    Canvas.SetTop(CalfLeft3, (jointPoints[JointType.KneeLeft].Y + jointPoints[JointType.AnkleLeft].Y) / 2 - (CalfLeft3.Height / 2));
                                    Canvas.SetLeft(CalfRight3, (jointPoints[JointType.KneeRight].X + jointPoints[JointType.AnkleRight].X) / 2 - (CalfRight3.Width / 2));
                                    Canvas.SetTop(CalfRight3, (jointPoints[JointType.KneeRight].Y + jointPoints[JointType.AnkleRight].Y) / 2 - (CalfRight3.Height / 2));

                                    Canvas.SetLeft(FootLeft3, jointPoints[JointType.FootLeft].X - (FootLeft3.Width / 2));
                                    Canvas.SetTop(FootLeft3, jointPoints[JointType.FootLeft].Y - (FootLeft3.Height / 2));
                                    Canvas.SetLeft(FootRight3, jointPoints[JointType.FootRight].X - (FootRight3.Width / 2));
                                    Canvas.SetTop(FootRight3, jointPoints[JointType.FootRight].Y - (FootRight3.Height / 2));
                                }
                            }
                            else if (body.TrackingId == bodyId[3])
                            {
                                // 影像尺寸（長寬必須等比例縮放）

                                if (Double.IsInfinity(faceLength) || Double.IsInfinity(shoulderLeftLength) ||
                                    Double.IsInfinity(shoulderRightLength) || Double.IsInfinity(upperArmLeftLength) ||
                                    Double.IsInfinity(upperArmRightLength) || Double.IsInfinity(lowerArmLeftLength) ||
                                    Double.IsInfinity(lowerArmRightLength) || Double.IsInfinity(handLeftLength) ||
                                    Double.IsInfinity(handRightLength) || Double.IsInfinity(upperBodyLength) ||
                                    Double.IsInfinity(lowerBodyLength) || Double.IsInfinity(thighLeftLength) ||
                                    Double.IsInfinity(thighRightLength) || Double.IsInfinity(calfLeftLength) ||
                                    Double.IsInfinity(calfRightLength) || Double.IsInfinity(footLeftLength) || Double.IsInfinity(footRightLength))
                                {
                                    Console.WriteLine("出現無限大！");
                                }
                                else
                                {
                                    this.DrawHandLeft(body.HandLeftState, puppetid, faceLength, handLeftAngle, jointPoints[JointType.HandLeft]);
                                    this.DrawHandRight(body.HandRightState, puppetid, faceLength, handRightAngle, jointPoints[JointType.HandRight]);

                                    Face4.Height = faceLength * 2.5;
                                    Face4.Width = Face4.ActualWidth * faceLength / Face4.ActualHeight * 2.5;

                                    ShoulderLeft4.Height = shoulderLeftLength * 2;
                                    ShoulderLeft4.Width = ShoulderLeft4.ActualWidth * shoulderLeftLength / ShoulderLeft4.ActualHeight * 2;
                                    ShoulderRight4.Height = shoulderRightLength * 2;
                                    ShoulderRight4.Width = ShoulderRight4.ActualWidth * shoulderRightLength / ShoulderRight4.ActualHeight * 2;

                                    UpperArmLeft4.Height = upperArmLeftLength * 1.5;
                                    UpperArmLeft4.Width = UpperArmLeft4.ActualWidth * upperArmLeftLength / UpperArmLeft4.ActualHeight * 1.5;
                                    UpperArmRight4.Height = upperArmRightLength * 1.5;
                                    UpperArmRight4.Width = UpperArmRight4.ActualWidth * upperArmRightLength / UpperArmRight4.ActualHeight * 1.5;

                                    LowerArmLeft4.Height = lowerArmLeftLength * 1.5;
                                    LowerArmLeft4.Width = LowerArmLeft4.ActualWidth * lowerArmLeftLength / LowerArmLeft4.ActualHeight * 1.5;
                                    LowerArmRight4.Height = lowerArmRightLength * 1.5;
                                    LowerArmRight4.Width = LowerArmRight4.ActualWidth * lowerArmRightLength / LowerArmRight4.ActualHeight * 1.5;

                                    HandLeft4.Height = lowerArmLeftLength * 1.5;
                                    HandLeft4.Width = HandLeft4.ActualWidth * lowerArmLeftLength / HandLeft4.ActualHeight * 1.5;
                                    HandRight4.Height = lowerArmRightLength * 1.5;
                                    HandRight4.Width = HandRight4.ActualWidth * lowerArmRightLength / HandRight4.ActualHeight * 1.5;

                                    UpperBody4.Height = upperBodyLength * 2;
                                    UpperBody4.Width = UpperBody4.ActualWidth * upperBodyLength / UpperBody4.ActualHeight * 2;
                                    LowerBody4.Height = lowerBodyLength * 1.2;
                                    LowerBody4.Width = LowerBody4.ActualWidth * lowerBodyLength / LowerBody4.ActualHeight * 1.2;

                                    ThighLeft4.Height = thighLeftLength * 1.5;
                                    ThighLeft4.Width = ThighLeft4.ActualWidth * thighLeftLength / ThighLeft4.ActualHeight * 1.5;
                                    ThighRight4.Height = thighRightLength * 1.5;
                                    ThighRight4.Width = ThighRight4.ActualWidth * thighRightLength / ThighRight4.ActualHeight * 1.5;

                                    CalfLeft4.Height = calfLeftLength;
                                    CalfLeft4.Width = CalfLeft4.ActualWidth * calfLeftLength / CalfLeft4.ActualHeight;
                                    CalfRight4.Height = calfRightLength;
                                    CalfRight4.Width = CalfRight4.ActualWidth * calfRightLength / CalfRight4.ActualHeight;

                                    FootLeft4.Height = footLeftLength * 2.5;
                                    FootLeft4.Width = FootLeft4.ActualWidth * footLeftLength / FootLeft4.ActualHeight * 2.5;
                                    FootRight4.Height = footRightLength * 2.5;
                                    FootRight4.Width = FootRight4.ActualWidth * footRightLength / FootRight4.ActualHeight * 2.5;

                                    // 影像旋轉

                                    RotateTransform faceRotate = new RotateTransform(faceAngle, Face4.Width / 2, Face4.Height / 2);
                                    Face4.RenderTransform = faceRotate;

                                    RotateTransform shoulderLeftRotate = new RotateTransform(shoulderLeftAngle, ShoulderLeft4.Width / 2, ShoulderLeft4.Height / 2);
                                    ShoulderLeft4.RenderTransform = shoulderLeftRotate;

                                    RotateTransform shoulderRightRotate = new RotateTransform(shoulderRightAngle, ShoulderRight4.Width / 2, ShoulderRight4.Height / 2);
                                    ShoulderRight4.RenderTransform = shoulderRightRotate;

                                    RotateTransform upperArmLeftRotate = new RotateTransform(upperArmLeftAngle, UpperArmLeft4.Width / 2, UpperArmLeft4.Height / 2);
                                    UpperArmLeft4.RenderTransform = upperArmLeftRotate;

                                    RotateTransform upperArmRightRotate = new RotateTransform(upperArmRightAngle, UpperArmRight4.Width / 2, UpperArmRight4.Height / 2);
                                    UpperArmRight4.RenderTransform = upperArmRightRotate;

                                    RotateTransform lowerArmLeftRotate = new RotateTransform(lowerArmLeftAngle, LowerArmLeft4.Width / 2, LowerArmLeft4.Height / 2);
                                    LowerArmLeft4.RenderTransform = lowerArmLeftRotate;

                                    RotateTransform lowerArmRightRotate = new RotateTransform(lowerArmRightAngle, LowerArmRight4.Width / 2, LowerArmRight4.Height / 2);
                                    LowerArmRight4.RenderTransform = lowerArmRightRotate;

                                    RotateTransform handLeftRotate = new RotateTransform(handLeftAngle, HandLeft4.Width / 2, HandLeft4.Height / 2);
                                    HandLeft4.RenderTransform = handLeftRotate;

                                    RotateTransform handRightRotate = new RotateTransform(handRightAngle, HandRight4.Width / 2, HandRight4.Height / 2);
                                    HandRight4.RenderTransform = handRightRotate;

                                    RotateTransform upperBodyRotate = new RotateTransform(upperBodyAngle, UpperBody4.Width / 2, UpperBody4.Height / 2);
                                    UpperBody4.RenderTransform = upperBodyRotate;

                                    RotateTransform lowerBodyRotate = new RotateTransform(lowerBodyAngle, LowerBody4.Width / 2, LowerBody4.Height / 2);
                                    LowerBody4.RenderTransform = lowerBodyRotate;

                                    RotateTransform thighLeftRotate = new RotateTransform(thighLeftAngle, ThighLeft4.Width / 2, ThighLeft4.Height / 2);
                                    ThighLeft4.RenderTransform = thighLeftRotate;

                                    RotateTransform thighRightRotate = new RotateTransform(thighRightAngle, ThighRight4.Width / 2, ThighRight4.Height / 2);
                                    ThighRight4.RenderTransform = thighRightRotate;

                                    RotateTransform calfLeftRotate = new RotateTransform(calfLeftAngle, CalfLeft4.Width / 2, CalfLeft4.Height / 2);
                                    CalfLeft4.RenderTransform = calfLeftRotate;

                                    RotateTransform calfRightRotate = new RotateTransform(calfRightAngle, CalfRight4.Width / 2, CalfRight4.Height / 2);
                                    CalfRight4.RenderTransform = calfRightRotate;

                                    RotateTransform footLeftRotate = new RotateTransform(footLeftAngle, FootLeft4.Width / 2, FootLeft4.Height / 2);
                                    FootLeft4.RenderTransform = footLeftRotate;

                                    RotateTransform footRightRotate = new RotateTransform(footRightAngle, FootRight4.Width / 2, FootRight4.Height / 2);
                                    FootRight4.RenderTransform = footRightRotate;

                                    // 將影像放到指定座標

                                    Canvas.SetLeft(Face4, jointPoints[JointType.Head].X - (Face4.Width / 2));
                                    Canvas.SetTop(Face4, jointPoints[JointType.Head].Y - (Face4.Height / 2));

                                    Canvas.SetLeft(ShoulderLeft4, jointPoints[JointType.ShoulderLeft].X - (ShoulderLeft4.Width / 2));
                                    Canvas.SetTop(ShoulderLeft4, jointPoints[JointType.ShoulderLeft].Y - (ShoulderLeft4.Height / 2));
                                    Canvas.SetLeft(ShoulderRight4, jointPoints[JointType.ShoulderRight].X - (ShoulderRight4.Width / 2));
                                    Canvas.SetTop(ShoulderRight4, jointPoints[JointType.ShoulderRight].Y - (ShoulderRight4.Height / 2));

                                    Canvas.SetLeft(UpperArmLeft4, (jointPoints[JointType.ShoulderLeft].X + jointPoints[JointType.ElbowLeft].X) / 2 - (UpperArmLeft4.Width / 2));
                                    Canvas.SetTop(UpperArmLeft4, (jointPoints[JointType.ShoulderLeft].Y + jointPoints[JointType.ElbowLeft].Y) / 2 - (UpperArmLeft4.Height / 2));
                                    Canvas.SetLeft(UpperArmRight4, (jointPoints[JointType.ShoulderRight].X + jointPoints[JointType.ElbowRight].X) / 2 - (UpperArmRight4.Width / 2));
                                    Canvas.SetTop(UpperArmRight4, (jointPoints[JointType.ShoulderRight].Y + jointPoints[JointType.ElbowRight].Y) / 2 - (UpperArmRight4.Height / 2));

                                    Canvas.SetLeft(LowerArmLeft4, (jointPoints[JointType.ElbowLeft].X + jointPoints[JointType.WristLeft].X) / 2 - (LowerArmLeft4.Width / 2));
                                    Canvas.SetTop(LowerArmLeft4, (jointPoints[JointType.ElbowLeft].Y + jointPoints[JointType.WristLeft].Y) / 2 - (LowerArmLeft4.Height / 2));

                                    Canvas.SetLeft(LowerArmRight4, (jointPoints[JointType.ElbowRight].X + jointPoints[JointType.WristRight].X) / 2 - (LowerArmRight4.Width / 2));
                                    Canvas.SetTop(LowerArmRight4, (jointPoints[JointType.ElbowRight].Y + jointPoints[JointType.WristRight].Y) / 2 - (LowerArmRight4.Height / 2));

                                    Canvas.SetLeft(HandLeft4, jointPoints[JointType.HandLeft].X - (HandLeft4.Width / 2));
                                    Canvas.SetTop(HandLeft4, jointPoints[JointType.HandLeft].Y - (HandLeft4.Height / 2));

                                    Canvas.SetLeft(HandRight4, jointPoints[JointType.HandRight].X - (HandRight4.Width / 2));
                                    Canvas.SetTop(HandRight4, jointPoints[JointType.HandRight].Y - (HandRight4.Height / 2));

                                    Canvas.SetLeft(UpperBody4, jointPoints[JointType.SpineMid].X - (UpperBody4.Width / 2));
                                    Canvas.SetTop(UpperBody4, jointPoints[JointType.SpineMid].Y - (UpperBody4.Height / 2));
                                    Canvas.SetLeft(LowerBody4, jointPoints[JointType.SpineBase].X - (LowerBody4.Width / 2));
                                    Canvas.SetTop(LowerBody4, jointPoints[JointType.SpineBase].Y + 10 - (LowerBody4.Height / 2));

                                    Canvas.SetLeft(ThighLeft4, (jointPoints[JointType.HipLeft].X + jointPoints[JointType.KneeLeft].X) / 2 - (ThighLeft4.Width / 2));
                                    Canvas.SetTop(ThighLeft4, (jointPoints[JointType.HipLeft].Y + jointPoints[JointType.KneeLeft].Y) / 2 - (ThighLeft4.Height / 2));
                                    Canvas.SetLeft(ThighRight4, (jointPoints[JointType.HipRight].X + jointPoints[JointType.KneeRight].X) / 2 - (ThighRight4.Width / 2));
                                    Canvas.SetTop(ThighRight4, (jointPoints[JointType.HipRight].Y + jointPoints[JointType.KneeRight].Y) / 2 - (ThighRight4.Height / 2));

                                    Canvas.SetLeft(CalfLeft4, (jointPoints[JointType.KneeLeft].X + jointPoints[JointType.AnkleLeft].X) / 2 - (CalfLeft4.Width / 2));
                                    Canvas.SetTop(CalfLeft4, (jointPoints[JointType.KneeLeft].Y + jointPoints[JointType.AnkleLeft].Y) / 2 - (CalfLeft4.Height / 2));
                                    Canvas.SetLeft(CalfRight4, (jointPoints[JointType.KneeRight].X + jointPoints[JointType.AnkleRight].X) / 2 - (CalfRight4.Width / 2));
                                    Canvas.SetTop(CalfRight4, (jointPoints[JointType.KneeRight].Y + jointPoints[JointType.AnkleRight].Y) / 2 - (CalfRight4.Height / 2));

                                    Canvas.SetLeft(FootLeft4, jointPoints[JointType.FootLeft].X - (FootLeft4.Width / 2));
                                    Canvas.SetTop(FootLeft4, jointPoints[JointType.FootLeft].Y - (FootLeft4.Height / 2));
                                    Canvas.SetLeft(FootRight4, jointPoints[JointType.FootRight].X - (FootRight4.Width / 2));
                                    Canvas.SetTop(FootRight4, jointPoints[JointType.FootRight].Y - (FootRight4.Height / 2));

                                    People.Opacity = 0;
                                }
                            }
                            else if (body.TrackingId == bodyId[4])
                            {
                                // 影像尺寸（長寬必須等比例縮放）

                                if (Double.IsInfinity(faceLength) || Double.IsInfinity(shoulderLeftLength) ||
                                    Double.IsInfinity(shoulderRightLength) || Double.IsInfinity(upperArmLeftLength) ||
                                    Double.IsInfinity(upperArmRightLength) || Double.IsInfinity(lowerArmLeftLength) ||
                                    Double.IsInfinity(lowerArmRightLength) || Double.IsInfinity(handLeftLength) ||
                                    Double.IsInfinity(handRightLength) || Double.IsInfinity(upperBodyLength) ||
                                    Double.IsInfinity(lowerBodyLength) || Double.IsInfinity(thighLeftLength) ||
                                    Double.IsInfinity(thighRightLength) || Double.IsInfinity(calfLeftLength) ||
                                    Double.IsInfinity(calfRightLength) || Double.IsInfinity(footLeftLength) || Double.IsInfinity(footRightLength))
                                {
                                    Console.WriteLine("出現無限大！");
                                }
                                else
                                {
                                    this.DrawHandLeft(body.HandLeftState, puppetid, faceLength, handLeftAngle, jointPoints[JointType.HandLeft]);
                                    this.DrawHandRight(body.HandRightState, puppetid, faceLength, handRightAngle, jointPoints[JointType.HandRight]);

                                    Face5.Height = faceLength * 2.5;
                                    Face5.Width = Face5.ActualWidth * faceLength / Face5.ActualHeight * 2.5;
                                    BlackPanther.Height = faceLength * 2.5;
                                    BlackPanther.Width = BlackPanther.ActualWidth * faceLength / BlackPanther.ActualHeight * 2.5;

                                    UpperArmLeft5.Height = upperArmLeftLength * 1.5;
                                    UpperArmLeft5.Width = UpperArmLeft5.ActualWidth * upperArmLeftLength / UpperArmLeft5.ActualHeight * 1.5;
                                    UpperArmRight5.Height = upperArmRightLength * 1.5;
                                    UpperArmRight5.Width = UpperArmRight5.ActualWidth * upperArmRightLength / UpperArmRight5.ActualHeight * 1.5;

                                    LowerArmLeft5.Height = lowerArmLeftLength * 1.5;
                                    LowerArmLeft5.Width = LowerArmLeft5.ActualWidth * lowerArmLeftLength / LowerArmLeft5.ActualHeight * 1.5;
                                    LowerArmRight5.Height = lowerArmRightLength * 1.5;
                                    LowerArmRight5.Width = LowerArmRight5.ActualWidth * lowerArmRightLength / LowerArmRight5.ActualHeight * 1.5;

                                    HandLeft5.Height = lowerArmLeftLength * 1.5;
                                    HandLeft5.Width = HandLeft5.ActualWidth * lowerArmLeftLength / HandLeft5.ActualHeight * 1.5;
                                    HandRight5.Height = lowerArmRightLength * 1.5;
                                    HandRight5.Width = HandRight5.ActualWidth * lowerArmRightLength / HandRight5.ActualHeight * 1.5;

                                    UpperBody5.Height = upperBodyLength * 2;
                                    UpperBody5.Width = UpperBody5.ActualWidth * upperBodyLength / UpperBody5.ActualHeight * 2;
                                    LowerBody5.Height = lowerBodyLength * 1.2;
                                    LowerBody5.Width = LowerBody5.ActualWidth * lowerBodyLength / LowerBody5.ActualHeight * 1.2;

                                    ThighLeft5.Height = thighLeftLength * 1.5;
                                    ThighLeft5.Width = ThighLeft5.ActualWidth * thighLeftLength / ThighLeft5.ActualHeight * 1.5;
                                    ThighRight5.Height = thighRightLength * 1.5;
                                    ThighRight5.Width = ThighRight5.ActualWidth * thighRightLength / ThighRight5.ActualHeight * 1.5;

                                    CalfLeft5.Height = calfLeftLength;
                                    CalfLeft5.Width = CalfLeft5.ActualWidth * calfLeftLength / CalfLeft5.ActualHeight;
                                    CalfRight5.Height = calfRightLength;
                                    CalfRight5.Width = CalfRight5.ActualWidth * calfRightLength / CalfRight5.ActualHeight;

                                    FootLeft5.Height = footLeftLength * 2.5;
                                    FootLeft5.Width = FootLeft5.ActualWidth * footLeftLength / FootLeft5.ActualHeight * 2.5;
                                    FootRight5.Height = footRightLength * 2.5;
                                    FootRight5.Width = FootRight5.ActualWidth * footRightLength / FootRight5.ActualHeight * 2.5;

                                    // 影像旋轉

                                    RotateTransform faceRotate = new RotateTransform(faceAngle, Face5.Width / 2, Face5.Height / 2);
                                    Face5.RenderTransform = faceRotate;
                                    BlackPanther.RenderTransform = faceRotate;

                                    RotateTransform upperArmLeftRotate = new RotateTransform(upperArmLeftAngle, UpperArmLeft5.Width / 2, UpperArmLeft5.Height / 2);
                                    UpperArmLeft5.RenderTransform = upperArmLeftRotate;

                                    RotateTransform upperArmRightRotate = new RotateTransform(upperArmRightAngle, UpperArmRight5.Width / 2, UpperArmRight5.Height / 2);
                                    UpperArmRight5.RenderTransform = upperArmRightRotate;

                                    RotateTransform lowerArmLeftRotate = new RotateTransform(lowerArmLeftAngle, LowerArmLeft5.Width / 2, LowerArmLeft5.Height / 2);
                                    LowerArmLeft5.RenderTransform = lowerArmLeftRotate;

                                    RotateTransform lowerArmRightRotate = new RotateTransform(lowerArmRightAngle, LowerArmRight5.Width / 2, LowerArmRight5.Height / 2);
                                    LowerArmRight5.RenderTransform = lowerArmRightRotate;

                                    RotateTransform handLeftRotate = new RotateTransform(handLeftAngle, HandLeft5.Width / 2, HandLeft5.Height / 2);
                                    HandLeft5.RenderTransform = handLeftRotate;

                                    RotateTransform handRightRotate = new RotateTransform(handRightAngle, HandRight5.Width / 2, HandRight5.Height / 2);
                                    HandRight5.RenderTransform = handRightRotate;

                                    RotateTransform upperBodyRotate = new RotateTransform(upperBodyAngle, UpperBody5.Width / 2, UpperBody5.Height / 2);
                                    UpperBody5.RenderTransform = upperBodyRotate;

                                    RotateTransform lowerBodyRotate = new RotateTransform(lowerBodyAngle, LowerBody5.Width / 2, LowerBody5.Height / 2);
                                    LowerBody5.RenderTransform = lowerBodyRotate;

                                    RotateTransform thighLeftRotate = new RotateTransform(thighLeftAngle, ThighLeft5.Width / 2, ThighLeft5.Height / 2);
                                    ThighLeft5.RenderTransform = thighLeftRotate;

                                    RotateTransform thighRightRotate = new RotateTransform(thighRightAngle, ThighRight5.Width / 2, ThighRight5.Height / 2);
                                    ThighRight5.RenderTransform = thighRightRotate;

                                    RotateTransform calfLeftRotate = new RotateTransform(calfLeftAngle, CalfLeft5.Width / 2, CalfLeft5.Height / 2);
                                    CalfLeft5.RenderTransform = calfLeftRotate;

                                    RotateTransform calfRightRotate = new RotateTransform(calfRightAngle, CalfRight5.Width / 2, CalfRight5.Height / 2);
                                    CalfRight5.RenderTransform = calfRightRotate;

                                    RotateTransform footLeftRotate = new RotateTransform(footLeftAngle, FootLeft5.Width / 2, FootLeft5.Height / 2);
                                    FootLeft5.RenderTransform = footLeftRotate;

                                    RotateTransform footRightRotate = new RotateTransform(footRightAngle, FootRight5.Width / 2, FootRight5.Height / 2);
                                    FootRight5.RenderTransform = footRightRotate;

                                    // 將影像放到指定座標
                                    
                                    Canvas.SetLeft(BlackPanther, jointPoints[JointType.Head].X - (BlackPanther.Width / 2));
                                    Canvas.SetTop(BlackPanther, jointPoints[JointType.Head].Y - (BlackPanther.Height / 2));
                                    Canvas.SetLeft(Face5, jointPoints[JointType.Head].X - (Face5.Width / 2));
                                    Canvas.SetTop(Face5, jointPoints[JointType.Head].Y - (Face5.Height / 2));

                                    Canvas.SetLeft(UpperArmLeft5, (jointPoints[JointType.ShoulderLeft].X + jointPoints[JointType.ElbowLeft].X) / 2 - (UpperArmLeft5.Width / 2));
                                    Canvas.SetTop(UpperArmLeft5, (jointPoints[JointType.ShoulderLeft].Y + jointPoints[JointType.ElbowLeft].Y) / 2 - (UpperArmLeft5.Height / 2));
                                    Canvas.SetLeft(UpperArmRight5, (jointPoints[JointType.ShoulderRight].X + jointPoints[JointType.ElbowRight].X) / 2 - (UpperArmRight5.Width / 2));
                                    Canvas.SetTop(UpperArmRight5, (jointPoints[JointType.ShoulderRight].Y + jointPoints[JointType.ElbowRight].Y) / 2 - (UpperArmRight5.Height / 2));

                                    Canvas.SetLeft(LowerArmLeft5, (jointPoints[JointType.ElbowLeft].X + jointPoints[JointType.WristLeft].X) / 2 - (LowerArmLeft5.Width / 2));
                                    Canvas.SetTop(LowerArmLeft5, (jointPoints[JointType.ElbowLeft].Y + jointPoints[JointType.WristLeft].Y) / 2 - (LowerArmLeft5.Height / 2));

                                    Canvas.SetLeft(LowerArmRight5, (jointPoints[JointType.ElbowRight].X + jointPoints[JointType.WristRight].X) / 2 - (LowerArmRight5.Width / 2));
                                    Canvas.SetTop(LowerArmRight5, (jointPoints[JointType.ElbowRight].Y + jointPoints[JointType.WristRight].Y) / 2 - (LowerArmRight5.Height / 2));

                                    Canvas.SetLeft(HandLeft5, jointPoints[JointType.HandLeft].X - (HandLeft5.Width / 2));
                                    Canvas.SetTop(HandLeft5, jointPoints[JointType.HandLeft].Y - (HandLeft5.Height / 2));

                                    Canvas.SetLeft(HandRight5, jointPoints[JointType.HandRight].X - (HandRight5.Width / 2));
                                    Canvas.SetTop(HandRight5, jointPoints[JointType.HandRight].Y - (HandRight5.Height / 2));

                                    Canvas.SetLeft(UpperBody5, jointPoints[JointType.SpineMid].X - (UpperBody5.Width / 2));
                                    Canvas.SetTop(UpperBody5, jointPoints[JointType.SpineMid].Y - (UpperBody5.Height / 2));
                                    Canvas.SetLeft(LowerBody5, jointPoints[JointType.SpineBase].X - (LowerBody5.Width / 2));
                                    Canvas.SetTop(LowerBody5, jointPoints[JointType.SpineBase].Y + 10 - (LowerBody5.Height / 2));

                                    Canvas.SetLeft(ThighLeft5, (jointPoints[JointType.HipLeft].X + jointPoints[JointType.KneeLeft].X) / 2 - (ThighLeft5.Width / 2));
                                    Canvas.SetTop(ThighLeft5, (jointPoints[JointType.HipLeft].Y + jointPoints[JointType.KneeLeft].Y) / 2 - (ThighLeft5.Height / 2));
                                    Canvas.SetLeft(ThighRight5, (jointPoints[JointType.HipRight].X + jointPoints[JointType.KneeRight].X) / 2 - (ThighRight5.Width / 2));
                                    Canvas.SetTop(ThighRight5, (jointPoints[JointType.HipRight].Y + jointPoints[JointType.KneeRight].Y) / 2 - (ThighRight5.Height / 2));

                                    Canvas.SetLeft(CalfLeft5, (jointPoints[JointType.KneeLeft].X + jointPoints[JointType.AnkleLeft].X) / 2 - (CalfLeft5.Width / 2));
                                    Canvas.SetTop(CalfLeft5, (jointPoints[JointType.KneeLeft].Y + jointPoints[JointType.AnkleLeft].Y) / 2 - (CalfLeft5.Height / 2));
                                    Canvas.SetLeft(CalfRight5, (jointPoints[JointType.KneeRight].X + jointPoints[JointType.AnkleRight].X) / 2 - (CalfRight5.Width / 2));
                                    Canvas.SetTop(CalfRight5, (jointPoints[JointType.KneeRight].Y + jointPoints[JointType.AnkleRight].Y) / 2 - (CalfRight5.Height / 2));

                                    Canvas.SetLeft(FootLeft5, jointPoints[JointType.FootLeft].X - (FootLeft5.Width / 2));
                                    Canvas.SetTop(FootLeft5, jointPoints[JointType.FootLeft].Y - (FootLeft5.Height / 2));
                                    Canvas.SetLeft(FootRight5, jointPoints[JointType.FootRight].X - (FootRight5.Width / 2));
                                    Canvas.SetTop(FootRight5, jointPoints[JointType.FootRight].Y - (FootRight5.Height / 2));

                                    People.Opacity = 0;
                                }
                            }
                            else if (body.TrackingId == bodyId[5])
                            {
                                // 影像尺寸（長寬必須等比例縮放）

                                if (Double.IsInfinity(faceLength) || Double.IsInfinity(shoulderLeftLength) ||
                                    Double.IsInfinity(shoulderRightLength) || Double.IsInfinity(upperArmLeftLength) ||
                                    Double.IsInfinity(upperArmRightLength) || Double.IsInfinity(lowerArmLeftLength) ||
                                    Double.IsInfinity(lowerArmRightLength) || Double.IsInfinity(handLeftLength) ||
                                    Double.IsInfinity(handRightLength) || Double.IsInfinity(upperBodyLength) ||
                                    Double.IsInfinity(lowerBodyLength) || Double.IsInfinity(thighLeftLength) ||
                                    Double.IsInfinity(thighRightLength) || Double.IsInfinity(calfLeftLength) ||
                                    Double.IsInfinity(calfRightLength) || Double.IsInfinity(footLeftLength) || Double.IsInfinity(footRightLength))
                                {
                                    Console.WriteLine("出現無限大！");
                                }
                                else
                                {
                                    this.DrawHandLeft(body.HandLeftState, puppetid, faceLength, handLeftAngle, jointPoints[JointType.HandLeft]);
                                    this.DrawHandRight(body.HandRightState, puppetid, faceLength, handRightAngle, jointPoints[JointType.HandRight]);

                                    Face6.Height = faceLength * 2.5;
                                    Face6.Width = Face6.ActualWidth * faceLength / Face6.ActualHeight * 2.5;
                                    Facechange3.Height = faceLength * 2.5;
                                    Facechange3.Width = Facechange3.ActualWidth * faceLength / Facechange3.ActualHeight * 2.5;

                                    UpperArmLeft6.Height = upperArmLeftLength * 1.5;
                                    UpperArmLeft6.Width = UpperArmLeft6.ActualWidth * upperArmLeftLength / UpperArmLeft6.ActualHeight * 1.5;
                                    UpperArmRight6.Height = upperArmRightLength * 1.5;
                                    UpperArmRight6.Width = UpperArmRight6.ActualWidth * upperArmRightLength / UpperArmRight6.ActualHeight * 1.5;

                                    LowerArmLeft6.Height = lowerArmLeftLength * 1.5;
                                    LowerArmLeft6.Width = LowerArmLeft6.ActualWidth * lowerArmLeftLength / LowerArmLeft6.ActualHeight * 1.5;
                                    LowerArmRight6.Height = lowerArmRightLength * 1.5;
                                    LowerArmRight6.Width = LowerArmRight6.ActualWidth * lowerArmRightLength / LowerArmRight6.ActualHeight * 1.5;

                                    HandLeft6.Height = lowerArmLeftLength * 1.5;
                                    HandLeft6.Width = HandLeft6.ActualWidth * lowerArmLeftLength / HandLeft6.ActualHeight * 1.5;
                                    HandRight6.Height = lowerArmRightLength * 1.5;
                                    HandRight6.Width = HandRight6.ActualWidth * lowerArmRightLength / HandRight6.ActualHeight * 1.5;

                                    UpperBody6.Height = upperBodyLength * 2;
                                    UpperBody6.Width = UpperBody6.ActualWidth * upperBodyLength / UpperBody6.ActualHeight * 2;
                                    LowerBody6.Height = lowerBodyLength * 1.2;
                                    LowerBody6.Width = LowerBody6.ActualWidth * lowerBodyLength / LowerBody6.ActualHeight * 1.2;

                                    ThighLeft6.Height = thighLeftLength * 1.5;
                                    ThighLeft6.Width = ThighLeft6.ActualWidth * thighLeftLength / ThighLeft6.ActualHeight * 1.5;
                                    ThighRight6.Height = thighRightLength * 1.5;
                                    ThighRight6.Width = ThighRight6.ActualWidth * thighRightLength / ThighRight6.ActualHeight * 1.5;

                                    CalfLeft6.Height = calfLeftLength;
                                    CalfLeft6.Width = CalfLeft6.ActualWidth * calfLeftLength / CalfLeft6.ActualHeight;
                                    CalfRight6.Height = calfRightLength;
                                    CalfRight6.Width = CalfRight6.ActualWidth * calfRightLength / CalfRight6.ActualHeight;

                                    FootLeft6.Height = footLeftLength * 2.5;
                                    FootLeft6.Width = FootLeft6.ActualWidth * footLeftLength / FootLeft6.ActualHeight * 2.5;
                                    FootRight6.Height = footRightLength * 2.5;
                                    FootRight6.Width = FootRight6.ActualWidth * footRightLength / FootRight6.ActualHeight * 2.5;

                                // 影像旋轉

                                RotateTransform faceRotate = new RotateTransform(faceAngle, Face6.Width / 2, Face6.Height / 2);
                                    Face6.RenderTransform = faceRotate;
                                    Facechange3.RenderTransform = faceRotate;

                                    RotateTransform upperArmLeftRotate = new RotateTransform(upperArmLeftAngle, UpperArmLeft6.Width / 2, UpperArmLeft6.Height / 2);
                                    UpperArmLeft6.RenderTransform = upperArmLeftRotate;

                                    RotateTransform upperArmRightRotate = new RotateTransform(upperArmRightAngle, UpperArmRight6.Width / 2, UpperArmRight6.Height / 2);
                                    UpperArmRight6.RenderTransform = upperArmRightRotate;

                                    RotateTransform lowerArmLeftRotate = new RotateTransform(lowerArmLeftAngle, LowerArmLeft6.Width / 2, LowerArmLeft6.Height / 2);
                                    LowerArmLeft6.RenderTransform = lowerArmLeftRotate;

                                    RotateTransform lowerArmRightRotate = new RotateTransform(lowerArmRightAngle, LowerArmRight6.Width / 2, LowerArmRight6.Height / 2);
                                    LowerArmRight6.RenderTransform = lowerArmRightRotate;

                                    RotateTransform handLeftRotate = new RotateTransform(handLeftAngle, HandLeft6.Width / 2, HandLeft6.Height / 2);
                                    HandLeft6.RenderTransform = handLeftRotate;

                                    RotateTransform handRightRotate = new RotateTransform(handRightAngle, HandRight6.Width / 2, HandRight6.Height / 2);
                                    HandRight6.RenderTransform = handRightRotate;

                                    RotateTransform upperBodyRotate = new RotateTransform(upperBodyAngle, UpperBody6.Width / 2, UpperBody6.Height / 2);
                                    UpperBody6.RenderTransform = upperBodyRotate;

                                    RotateTransform lowerBodyRotate = new RotateTransform(lowerBodyAngle, LowerBody6.Width / 2, LowerBody6.Height / 2);
                                    LowerBody6.RenderTransform = lowerBodyRotate;

                                    RotateTransform thighLeftRotate = new RotateTransform(thighLeftAngle, ThighLeft6.Width / 2, ThighLeft6.Height / 2);
                                    ThighLeft6.RenderTransform = thighLeftRotate;

                                    RotateTransform thighRightRotate = new RotateTransform(thighRightAngle, ThighRight6.Width / 2, ThighRight6.Height / 2);
                                    ThighRight6.RenderTransform = thighRightRotate;

                                    RotateTransform calfLeftRotate = new RotateTransform(calfLeftAngle, CalfLeft6.Width / 2, CalfLeft6.Height / 2);
                                    CalfLeft6.RenderTransform = calfLeftRotate;

                                    RotateTransform calfRightRotate = new RotateTransform(calfRightAngle, CalfRight6.Width / 2, CalfRight6.Height / 2);
                                    CalfRight6.RenderTransform = calfRightRotate;

                                    RotateTransform footLeftRotate = new RotateTransform(footLeftAngle, FootLeft6.Width / 2, FootLeft6.Height / 2);
                                    FootLeft6.RenderTransform = footLeftRotate;

                                    RotateTransform footRightRotate = new RotateTransform(footRightAngle, FootRight6.Width / 2, FootRight6.Height / 2);
                                    FootRight6.RenderTransform = footRightRotate;

                                // 將影像放到指定座標

                                Canvas.SetLeft(Face6, jointPoints[JointType.Head].X - (Face6.Width / 2));
                                    Canvas.SetTop(Face6, jointPoints[JointType.Head].Y - (Face6.Height / 2));
                                    Canvas.SetLeft(Facechange3, jointPoints[JointType.Head].X - (Face6.Width / 2));
                                    Canvas.SetTop(Facechange3, jointPoints[JointType.Head].Y - (Face6.Height / 2));

                                    Canvas.SetLeft(UpperArmLeft6, (jointPoints[JointType.ShoulderLeft].X + jointPoints[JointType.ElbowLeft].X) / 2 - (UpperArmLeft6.Width / 2));
                                    Canvas.SetTop(UpperArmLeft6, (jointPoints[JointType.ShoulderLeft].Y + jointPoints[JointType.ElbowLeft].Y) / 2 - (UpperArmLeft6.Height / 2));
                                    Canvas.SetLeft(UpperArmRight6, (jointPoints[JointType.ShoulderRight].X + jointPoints[JointType.ElbowRight].X) / 2 - (UpperArmRight6.Width / 2));
                                    Canvas.SetTop(UpperArmRight6, (jointPoints[JointType.ShoulderRight].Y + jointPoints[JointType.ElbowRight].Y) / 2 - (UpperArmRight6.Height / 2));

                                    Canvas.SetLeft(LowerArmLeft6, (jointPoints[JointType.ElbowLeft].X + jointPoints[JointType.WristLeft].X) / 2 - (LowerArmLeft6.Width / 2));
                                    Canvas.SetTop(LowerArmLeft6, (jointPoints[JointType.ElbowLeft].Y + jointPoints[JointType.WristLeft].Y) / 2 - (LowerArmLeft6.Height / 2));

                                    Canvas.SetLeft(LowerArmRight6, (jointPoints[JointType.ElbowRight].X + jointPoints[JointType.WristRight].X) / 2 - (LowerArmRight6.Width / 2));
                                    Canvas.SetTop(LowerArmRight6, (jointPoints[JointType.ElbowRight].Y + jointPoints[JointType.WristRight].Y) / 2 - (LowerArmRight6.Height / 2));

                                    Canvas.SetLeft(HandLeft6, jointPoints[JointType.HandLeft].X - (HandLeft6.Width / 2));
                                    Canvas.SetTop(HandLeft6, jointPoints[JointType.HandLeft].Y - (HandLeft6.Height / 2));

                                    Canvas.SetLeft(HandRight6, jointPoints[JointType.HandRight].X - (HandRight6.Width / 2));
                                    Canvas.SetTop(HandRight6, jointPoints[JointType.HandRight].Y - (HandRight6.Height / 2));

                                    Canvas.SetLeft(UpperBody6, jointPoints[JointType.SpineMid].X - (UpperBody6.Width / 2));
                                    Canvas.SetTop(UpperBody6, jointPoints[JointType.SpineMid].Y - (UpperBody6.Height / 2));
                                    Canvas.SetLeft(LowerBody6, jointPoints[JointType.SpineBase].X - (LowerBody6.Width / 2));
                                    Canvas.SetTop(LowerBody6, jointPoints[JointType.SpineBase].Y + 10 - (LowerBody6.Height / 2));

                                    Canvas.SetLeft(ThighLeft6, (jointPoints[JointType.HipLeft].X + jointPoints[JointType.KneeLeft].X) / 2 - (ThighLeft6.Width / 2));
                                    Canvas.SetTop(ThighLeft6, (jointPoints[JointType.HipLeft].Y + jointPoints[JointType.KneeLeft].Y) / 2 - (ThighLeft6.Height / 2));
                                    Canvas.SetLeft(ThighRight6, (jointPoints[JointType.HipRight].X + jointPoints[JointType.KneeRight].X) / 2 - (ThighRight6.Width / 2));
                                    Canvas.SetTop(ThighRight6, (jointPoints[JointType.HipRight].Y + jointPoints[JointType.KneeRight].Y) / 2 - (ThighRight6.Height / 2));

                                    Canvas.SetLeft(CalfLeft6, (jointPoints[JointType.KneeLeft].X + jointPoints[JointType.AnkleLeft].X) / 2 - (CalfLeft6.Width / 2));
                                    Canvas.SetTop(CalfLeft6, (jointPoints[JointType.KneeLeft].Y + jointPoints[JointType.AnkleLeft].Y) / 2 - (CalfLeft6.Height / 2));
                                    Canvas.SetLeft(CalfRight6, (jointPoints[JointType.KneeRight].X + jointPoints[JointType.AnkleRight].X) / 2 - (CalfRight6.Width / 2));
                                    Canvas.SetTop(CalfRight6, (jointPoints[JointType.KneeRight].Y + jointPoints[JointType.AnkleRight].Y) / 2 - (CalfRight6.Height / 2));
                                    Canvas.SetLeft(FootLeft6, jointPoints[JointType.FootLeft].X - (FootLeft6.Width / 2));
                                    Canvas.SetTop(FootLeft6, jointPoints[JointType.FootLeft].Y - (FootLeft6.Height / 2));
                                    Canvas.SetLeft(FootRight6, jointPoints[JointType.FootRight].X - (FootRight6.Width / 2));
                                    Canvas.SetTop(FootRight6, jointPoints[JointType.FootRight].Y - (FootRight6.Height / 2));
                                People.Opacity = 0;
                                }
                            }
                        if ((puppetid == 1) && (jointPoints[JointType.HandLeft].Y <= jointPoints[JointType.Head].Y) && (jointPoints[JointType.HandLeft].X >= jointPoints[JointType.Head].X))
                        {
                            Face2.Opacity = 0;
                            Facechange.Opacity = 1;                          
                        }
                        else if ((puppetid == 2) && (jointPoints[JointType.HandLeft].Y <= jointPoints[JointType.Head].Y) && (jointPoints[JointType.HandLeft].X >= jointPoints[JointType.Head].X))
                        {
                            Face3.Opacity = 0;
                            Facechange2.Opacity = 1;                            
                        }
                        else if ((puppetid == 5) && (jointPoints[JointType.HandLeft].Y <= jointPoints[JointType.Head].Y) && (jointPoints[JointType.HandLeft].X >= jointPoints[JointType.Head].X))
                        {
                            Face6.Opacity = 0;
                            Facechange3.Opacity = 1;                           
                        }
                        if ((puppetid == 1) && (jointPoints[JointType.HandRight].Y <= jointPoints[JointType.Head].Y) && (jointPoints[JointType.HandRight].X <= jointPoints[JointType.Head].X))
                        {
                            Face2.Opacity = 1;
                            Facechange.Opacity = 0;                            
                        }
                        else if ((puppetid == 2) && (jointPoints[JointType.HandRight].Y <= jointPoints[JointType.Head].Y) && (jointPoints[JointType.HandRight].X <= jointPoints[JointType.Head].X))
                        {
                            Face3.Opacity = 1;
                            Facechange2.Opacity = 0;                            
                        }
                        else if ((puppetid == 5) && (jointPoints[JointType.HandRight].Y <= jointPoints[JointType.Head].Y) && (jointPoints[JointType.HandRight].X <= jointPoints[JointType.Head].X))
                        {
                            Face6.Opacity = 1;
                            Facechange3.Opacity = 0;
                            /*if (!speechRecognition)
                            {
                                speechRecognition = true;
                                this.CreateMicrophoneRecoClient();
                                this.micClient.StartMicAndRecognition();
                            }*/
                        }
                        


                        }
                    else if (!body.IsTracked)
                        {
                            bool[] existence = new bool[6];

                            for (int i = 0; i < 6; i++)
                            {
                                for (int j = 0; j < 6; j++)
                                {
                                    if (bodyId[i] == bodyStatus[j])
                                    {
                                        existence[i] = true;
                                    }
                                }
                            }

                            //People.Opacity = 1;

                            if (!existence[0])
                            {
                                bodyId[0] = 0;
                                wearing[0] = false;

                                if (this.micClient != null)
                                {
                                    speechRecognition = false;
                                    this.micClient.EndMicAndRecognition();
                                }

                                Face.Height = 0;
                                Face.Width = 0;
                                Smile.Height = 0;
                                Smile.Width = 0;

                                ShoulderLeft.Height = 0;
                                ShoulderLeft.Width = 0;
                                ShoulderRight.Height = 0;
                                ShoulderRight.Width = 0;

                                UpperArmLeft.Height = 0;
                                UpperArmLeft.Width = 0;
                                UpperArmRight.Height = 0;
                                UpperArmRight.Width = 0;

                                LowerArmLeft.Height = 0;
                                LowerArmLeft.Width = 0;
                                LowerArmRight.Height = 0;
                                LowerArmRight.Width = 0;

                                HandLeft.Height = 0;
                                HandLeft.Width = 0;
                                HandRight.Height = 0;
                                HandRight.Width = 0;

                                UpperBody.Height = 0;
                                UpperBody.Width = 0;
                                LowerBody.Height = 0;
                                LowerBody.Width = 0;

                                ThighLeft.Height = 0;
                                ThighLeft.Width = 0;
                                ThighRight.Height = 0;
                                ThighRight.Width = 0;

                                CalfLeft.Height = 0;
                                CalfLeft.Width = 0;
                                CalfRight.Height = 0;
                                CalfRight.Width = 0;

                                FootLeft.Height = 0;
                                FootLeft.Width = 0;
                                FootRight.Height = 0;
                                FootRight.Width = 0;

                                PowerLeft.Height = 0;
                                PowerLeft.Width = 0;
                            }
                            else if (!existence[1])
                            {
                                bodyId[1] = 0;
                                wearing[1] = false;

                                Face2.Height = 0;
                                Face2.Width = 0;
                                Facechange.Height = 0;
                                Facechange.Width = 0;

                                ShoulderLeft2.Height = 0;
                                ShoulderLeft2.Width = 0;
                                ShoulderRight2.Height = 0;
                                ShoulderRight2.Width = 0;

                                UpperArmLeft2.Height = 0;
                                UpperArmLeft2.Width = 0;
                                UpperArmRight2.Height = 0;
                                UpperArmRight2.Width = 0;

                                LowerArmLeft2.Height = 0;
                                LowerArmLeft2.Width = 0;
                                LowerArmRight2.Height = 0;
                                LowerArmRight2.Width = 0;

                                HandLeft2.Height = 0;
                                HandLeft2.Width = 0;
                                HandRight2.Height = 0;
                                HandRight2.Width = 0;

                                UpperBody2.Height = 0;
                                UpperBody2.Width = 0;
                                LowerBody2.Height = 0;
                                LowerBody2.Width = 0;

                                ThighLeft2.Height = 0;
                                ThighLeft2.Width = 0;
                                ThighRight2.Height = 0;
                                ThighRight2.Width = 0;

                                CalfLeft2.Height = 0;
                                CalfLeft2.Width = 0;
                                CalfRight2.Height = 0;
                                CalfRight2.Width = 0;

                                FootLeft2.Height = 0;
                                FootLeft2.Width = 0;
                                FootRight2.Height = 0;
                                FootRight2.Width = 0;

                                PowerLeft2.Height = 0;
                                PowerLeft2.Width = 0;
                                PowerRight2.Height = 0;
                                PowerRight2.Width = 0;
                            }
                            else if (!existence[2])
                            {
                                bodyId[2] = 0;
                                wearing[2] = false;

                                Face3.Height = 0;
                                Face3.Width = 0;
                                Facechange2.Height = 0;
                                Facechange2.Width = 0;

                                ShoulderLeft3.Height = 0;
                                ShoulderLeft3.Width = 0;
                                ShoulderRight3.Height = 0;
                                ShoulderRight3.Width = 0;

                                UpperArmLeft3.Height = 0;
                                UpperArmLeft3.Width = 0;
                                UpperArmRight3.Height = 0;
                                UpperArmRight3.Width = 0;

                                LowerArmLeft3.Height = 0;
                                LowerArmLeft3.Width = 0;
                                LowerArmRight3.Height = 0;
                                LowerArmRight3.Width = 0;

                                HandLeft3.Height = 0;
                                HandLeft3.Width = 0;
                                HandRight3.Height = 0;
                                HandRight3.Width = 0;

                                UpperBody3.Height = 0;
                                UpperBody3.Width = 0;
                                LowerBody3.Height = 0;
                                LowerBody3.Width = 0;

                                ThighLeft3.Height = 0;
                                ThighLeft3.Width = 0;
                                ThighRight3.Height = 0;
                                ThighRight3.Width = 0;

                                CalfLeft3.Height = 0;
                                CalfLeft3.Width = 0;
                                CalfRight3.Height = 0;
                                CalfRight3.Width = 0;

                                FootLeft3.Height = 0;
                                FootLeft3.Width = 0;
                                FootRight3.Height = 0;
                                FootRight3.Width = 0;

                                PowerLeft3.Height = 0;
                                PowerLeft3.Width = 0;
                                PowerRight3.Height = 0;
                                PowerRight3.Width = 0;
                            }
                            else if (!existence[3])
                            {
                                bodyId[3] = 0;
                                wearing[3] = false;

                                Face4.Height = 0;
                                Face4.Width = 0;

                                ShoulderLeft4.Height = 0;
                                ShoulderLeft4.Width = 0;
                                ShoulderRight4.Height = 0;
                                ShoulderRight4.Width = 0;

                                UpperArmLeft4.Height = 0;
                                UpperArmLeft4.Width = 0;
                                UpperArmRight4.Height = 0;
                                UpperArmRight4.Width = 0;

                                LowerArmLeft4.Height = 0;
                                LowerArmLeft4.Width = 0;
                                LowerArmRight4.Height = 0;
                                LowerArmRight4.Width = 0;

                                HandLeft4.Height = 0;
                                HandLeft4.Width = 0;
                                HandRight4.Height = 0;
                                HandRight4.Width = 0;

                                UpperBody4.Height = 0;
                                UpperBody4.Width = 0;
                                LowerBody4.Height = 0;
                                LowerBody4.Width = 0;

                                ThighLeft4.Height = 0;
                                ThighLeft4.Width = 0;
                                ThighRight4.Height = 0;
                                ThighRight4.Width = 0;

                                CalfLeft4.Height = 0;
                                CalfLeft4.Width = 0;
                                CalfRight4.Height = 0;
                                CalfRight4.Width = 0;

                                FootLeft4.Height = 0;
                                FootLeft4.Width = 0;
                                FootRight4.Height = 0;
                                FootRight4.Width = 0;

                                PowerLeft4.Height = 0;
                                PowerLeft4.Width = 0;
                                PowerRight4.Height = 0;
                                PowerRight4.Width = 0;
                            }
                            else if (!existence[4])
                            {
                                bodyId[4] = 0;
                                wearing[4] = false;

                                Face5.Height = 0;
                                Face5.Width = 0;
                                BlackPanther.Height = 0;
                                BlackPanther.Width = 0;

                                UpperArmLeft5.Height = 0;
                                UpperArmLeft5.Width = 0;
                                UpperArmRight5.Height = 0;
                                UpperArmRight5.Width = 0;

                                LowerArmLeft5.Height = 0;
                                LowerArmLeft5.Width = 0;
                                LowerArmRight5.Height = 0;
                                LowerArmRight5.Width = 0;

                                HandLeft5.Height = 0;
                                HandLeft5.Width = 0;
                                HandRight5.Height = 0;
                                HandRight5.Width = 0;

                                UpperBody5.Height = 0;
                                UpperBody5.Width = 0;
                                LowerBody5.Height = 0;
                                LowerBody5.Width = 0;

                                ThighLeft5.Height = 0;
                                ThighLeft5.Width = 0;
                                ThighRight5.Height = 0;
                                ThighRight5.Width = 0;

                                CalfLeft5.Height = 0;
                                CalfLeft5.Width = 0;
                                CalfRight5.Height = 0;
                                CalfRight5.Width = 0;

                                FootLeft5.Height = 0;
                                FootLeft5.Width = 0;
                                FootRight5.Height = 0;
                                FootRight5.Width = 0;
                            }
                            else if (!existence[5])
                            {
                                bodyId[5] = 0;
                                wearing[5] = false;

                                Face6.Height = 0;
                                Face6.Width = 0;
                                Facechange3.Height = 0;
                                Facechange3.Width = 0;

                                UpperArmLeft6.Height = 0;
                                UpperArmLeft6.Width = 0;
                                UpperArmRight6.Height = 0;
                                UpperArmRight6.Width = 0;

                                LowerArmLeft6.Height = 0;
                                LowerArmLeft6.Width = 0;
                                LowerArmRight6.Height = 0;
                                LowerArmRight6.Width = 0;

                                HandLeft6.Height = 0;
                                HandLeft6.Width = 0;
                                HandRight6.Height = 0;
                                HandRight6.Width = 0;

                                UpperBody6.Height = 0;
                                UpperBody6.Width = 0;
                                LowerBody6.Height = 0;
                                LowerBody6.Width = 0;

                                ThighLeft6.Height = 0;
                                ThighLeft6.Width = 0;
                                ThighRight6.Height = 0;
                                ThighRight6.Width = 0;

                                CalfLeft6.Height = 0;
                                CalfLeft6.Width = 0;
                                CalfRight6.Height = 0;
                                CalfRight6.Width = 0;
                                FootLeft6.Height = 0;
                                FootLeft6.Width = 0;
                                FootRight6.Height = 0;
                                FootRight6.Width = 0;
                                PowerLeft6.Height = 0;
                                PowerLeft6.Width = 0;
                                PowerRight6.Height = 0;
                                PowerRight6.Width = 0;
                            }
                        }
                    }
            }
        }

        private void DrawHandLeft(HandState handState, int puppetId, double faceLength, double handLeftAngle, Point handLeftPosition)
        {
            if (puppetId == 0)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerLeft.Height = faceLength * powerSize[puppetId];
                        PowerLeft.Width = PowerLeft.ActualWidth * faceLength / PowerLeft.ActualHeight * powerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handLeftAngle, PowerLeft.Width / 2, PowerLeft.Height / 2);
                        PowerLeft.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerLeft, handLeftPosition.X - PowerLeft.Width / 2);
                        Canvas.SetTop(PowerLeft, handLeftPosition.Y - PowerLeft.Height / 2);
                        PowerLeft.Opacity = 1;

                        break;

                    case HandState.Open:

                        Face.Opacity = 1;
                        Smile.Opacity = 0;
                        PowerLeft.Opacity = 0;

                        break;

                    case HandState.Lasso:

                        Face.Opacity = 0;
                        Smile.Opacity = 0;

                        break;
                }
            }
            else if (puppetId == 1)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerLeft2.Height = faceLength * powerSize[puppetId];
                        PowerLeft2.Width = PowerLeft2.ActualWidth * faceLength / PowerLeft2.ActualHeight * powerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handLeftAngle, PowerLeft2.Width / 2, PowerLeft2.Height / 2);
                        PowerLeft2.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerLeft2, handLeftPosition.X - PowerLeft2.Width / 2);
                        Canvas.SetTop(PowerLeft2, handLeftPosition.Y - PowerLeft2.Height / 2);
                        PowerLeft2.Opacity = 1;

                        break;

                    case HandState.Open:
                        Canvas.SetLeft(PowerLeft2, Canvas.GetLeft(PowerLeft2) - 10);
                        break;

                    case HandState.Lasso:

                        PowerLeft2.Opacity = 0;

                        break;                    
                }
            }
            else if (puppetId == 2)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerLeft3.Height = faceLength * powerSize[puppetId];
                        PowerLeft3.Width = PowerLeft3.ActualWidth * faceLength / PowerLeft3.ActualHeight * powerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handLeftAngle, PowerLeft3.Width / 2, PowerLeft3.Height / 2);
                        PowerLeft3.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerLeft3, handLeftPosition.X - PowerLeft3.Width / 2);
                        Canvas.SetTop(PowerLeft3, handLeftPosition.Y - PowerLeft3.Height / 2);
                        PowerLeft3.Opacity = 1;

                        break;

                    case HandState.Open:

                        break;

                    case HandState.Lasso:

                        PowerLeft3.Opacity = 0;

                        break;
                }
            }
            else if (puppetId == 3)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerLeft4.Height = faceLength * powerSize[puppetId];
                        PowerLeft4.Width = PowerLeft4.ActualWidth * faceLength / PowerLeft4.ActualHeight * powerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handLeftAngle, PowerLeft4.Width / 2, PowerLeft4.Height / 2);
                        PowerLeft4.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerLeft4, handLeftPosition.X - PowerLeft4.Width / 2);
                        Canvas.SetTop(PowerLeft4, handLeftPosition.Y - PowerLeft4.Height / 2);
                        PowerLeft4.Opacity = 1;

                        break;

                    case HandState.Open:

                        break;

                    case HandState.Lasso:

                        PowerLeft4.Opacity = 0;

                        break;
                }
            }
            else if (puppetId == 4)
            {
                switch (handState)
                {
                    case HandState.Closed:
                        Face5.Opacity = 0;
                        BlackPanther.Opacity = 1;
                        break;

                    case HandState.Open:
                        Face5.Opacity = 1;
                        BlackPanther.Opacity = 0;
                        break;

                    case HandState.Lasso:

                        break;
                }
            }
            else if (puppetId == 5)
            {
                switch (handState)
                {
                    case HandState.Closed:
                        PowerLeft6.Height = faceLength * powerSize[puppetId];
                        PowerLeft6.Width = PowerLeft6.ActualWidth * faceLength / PowerLeft6.ActualHeight * powerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handLeftAngle, PowerLeft6.Width / 2, PowerLeft6.Height / 2);
                        PowerLeft6.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerLeft6, handLeftPosition.X - PowerLeft6.Width / 2);
                        Canvas.SetTop(PowerLeft6, handLeftPosition.Y - PowerLeft6.Height / 2);
                        PowerLeft6.Opacity = 1;
                        break;

                    case HandState.Open:
                        Canvas.SetLeft(PowerLeft6, Canvas.GetLeft(PowerLeft6) - 10);
                        break;

                    case HandState.Lasso:
                        PowerLeft6.Opacity = 0;
                        break;
                }
            }
        }

        private void DrawHandRight(HandState handState, int puppetId, double faceLength, double handRightAngle, Point handRightPosition)
        {
            if (puppetId == 0)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        Face.Opacity = 0;
                        Smile.Opacity = 1;
                        if (!speechRecognition)
                        {
                            speechRecognition = true;
                            this.CreateMicrophoneRecoClient();
                            this.micClient.StartMicAndRecognition();
                        }

                        break;

                    case HandState.Open:

                        break;

                    case HandState.Lasso:

                        Smile.Opacity = 0;
                        Face.Opacity = 1;

                        if (this.micClient != null)
                        {
                            speechRecognition = false;
                            this.micClient.EndMicAndRecognition();
                        }

                        break;
                }
            }
            else if (puppetId == 1)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerRight2.Height = faceLength * originalPowerSize[puppetId];
                        PowerRight2.Width = PowerRight2.ActualWidth * faceLength / PowerRight2.ActualHeight * originalPowerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handRightAngle, PowerRight2.Width / 2, PowerRight2.Height / 2);
                        PowerRight2.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerRight2, handRightPosition.X - PowerRight2.Width / 2);
                        Canvas.SetTop(PowerRight2, handRightPosition.Y - PowerRight2.Height / 2);
                        PowerRight2.Opacity = 1;

                        break;

                    case HandState.Open:
                        Canvas.SetLeft(PowerRight2, Canvas.GetLeft(PowerRight2) + 10);
                        break;

                    case HandState.Lasso:

                        PowerRight2.Opacity = 0;

                        break;
                }
            }
            else if (puppetId == 2)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerRight3.Height = faceLength * originalPowerSize[puppetId];
                        PowerRight3.Width = PowerRight3.ActualWidth * faceLength / PowerRight3.ActualHeight * originalPowerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handRightAngle, PowerRight3.Width / 2, PowerRight3.Height / 2);
                        PowerRight3.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerRight3, handRightPosition.X - PowerRight3.Width / 2);
                        Canvas.SetTop(PowerRight3, handRightPosition.Y - PowerRight3.Height / 2);
                        PowerRight3.Opacity = 1;

                        break;

                    case HandState.Open:

                        break;

                    case HandState.Lasso:

                        PowerRight3.Opacity = 0;

                        break;
                }
            }
            else if (puppetId == 3)
            {
                switch (handState)
                {
                    case HandState.Closed:

                        PowerRight4.Height = faceLength * originalPowerSize[puppetId];
                        PowerRight4.Width = PowerRight4.ActualWidth * faceLength / PowerRight4.ActualHeight * originalPowerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handRightAngle, PowerRight4.Width / 2, PowerRight4.Height / 2);
                        PowerRight4.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerRight4, handRightPosition.X - PowerRight4.Width / 2);
                        Canvas.SetTop(PowerRight4, handRightPosition.Y - PowerRight4.Height / 2);
                        PowerRight4.Opacity = 1;

                        break;

                    case HandState.Open:

                        break;

                    case HandState.Lasso:

                        PowerRight4.Opacity = 0;

                        break;
                }
            }
            else if (puppetId == 4)
            {
                switch (handState)
                {
                    case HandState.Closed:
                        
                        break;

                    case HandState.Open:
                        
                        break;

                    case HandState.Lasso:

                        break;
                }
            }
            else if (puppetId == 5)
            {
                switch (handState)
                {
                    case HandState.Closed:
                        PowerRight6.Height = faceLength * originalPowerSize[puppetId];
                        PowerRight6.Width = PowerRight6.ActualWidth * faceLength / PowerRight6.ActualHeight * originalPowerSize[puppetId];

                        RotateTransform handRotate = new RotateTransform(handRightAngle, PowerRight6.Width / 2, PowerRight6.Height / 2);
                        PowerRight6.RenderTransform = handRotate;

                        Canvas.SetLeft(PowerRight6, handRightPosition.X - PowerRight6.Width / 2);
                        Canvas.SetTop(PowerRight6, handRightPosition.Y - PowerRight6.Height / 2);
                        PowerRight6.Opacity = 1;
                        break;

                    case HandState.Open:
                        Canvas.SetLeft(PowerRight6, Canvas.GetLeft(PowerRight6) + 10);
                        break;

                    case HandState.Lasso:
                        PowerRight6.Opacity = 0;
                        break;
                }
            }
        }

        private void ShowDialogue(string text)
        {
            this.Dispatcher.Invoke(new Action(() =>
            {
                Console.WriteLine(text);
                Dialogue.Text = text;
                FadeOutAnimation(500);
            }));
        }

        private void ChangeDialogue(string text)
        {
            this.Dispatcher.Invoke(new Action(() =>
            {
                if (text == "")
                {
                    Dialogue.Text = "";
                    Dialogue.Visibility = Visibility.Hidden;
                }
                else
                {
                    Dialogue.Visibility = Visibility.Visible;
                }
            }));
        }

        private void ShowResponse(string response)
        {
            if (response == "Action!")
            {
                this.Dispatcher.Invoke(DispatcherPriority.Normal, new Action<String, String, double>(StartAni), response, "#A20025", 1);
            }
            else
            {
                this.Dispatcher.Invoke(DispatcherPriority.Normal, new Action<String, String, double>(StartAni), response, "#888888", 2);
            }
        }

        private void ShowMagic(int spell)
        {
            this.Dispatcher.Invoke(new Action(() =>
            {
                switch (spell)
                {
                    case 0:
                        playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Rainy.mp3");
                        Thread.Sleep(1000);
                        Rainy.Opacity = 1;
                        break;
                    case 1:
                        playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Flood.mp3");
                        Thread.Sleep(1000);
                        Flood.Opacity = 0.9;
                        break;
                    case 2:
                        /*
                        Face.Opacity = 0;
                        Smile.Opacity = 0;
                        ShoulderLeft.Opacity = 0;
                        ShoulderRight.Opacity = 0;
                        UpperArmLeft.Opacity = 0;
                        UpperArmRight.Opacity = 0;
                        LowerArmLeft.Opacity = 0;
                        LowerArmRight.Opacity = 0;
                        HandLeft.Opacity = 0;
                        HandRight.Opacity = 0;
                        UpperBody.Opacity = 0;
                        LowerBody.Opacity = 0;
                        ThighLeft.Opacity = 0;
                        ThighRight.Opacity = 0;
                        CalfLeft.Opacity = 0;
                        CalfRight.Opacity = 0;
                        FootLeft.Opacity = 0;
                        FootRight.Opacity = 0;
                        */
                        playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Fire.mp3");
                        Thread.Sleep(1000);
                        People.Opacity = 0;
                        break;
                    case 3:
                        /*
                        Face.Opacity = 1;
                        Smile.Opacity = 0;
                        ShoulderLeft.Opacity = 1;
                        ShoulderRight.Opacity = 1;
                        UpperArmLeft.Opacity = 1;
                        UpperArmRight.Opacity = 1;
                        LowerArmLeft.Opacity = 1;
                        LowerArmRight.Opacity = 1;
                        HandLeft.Opacity = 1;
                        HandRight.Opacity = 1;
                        UpperBody.Opacity = 1;
                        LowerBody.Opacity = 1;
                        ThighLeft.Opacity = 1;
                        ThighRight.Opacity = 1;
                        CalfLeft.Opacity = 1;
                        CalfRight.Opacity = 1;
                        FootLeft.Opacity = 1;
                        FootRight.Opacity = 1;
                        */
                        playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Fire.mp3");
                        Thread.Sleep(1000);
                        People.Opacity = 1;
                        break;
                    case 4:
                        Rainy.Opacity = 0;
                        Flood.Opacity = 0;
                        Face.Opacity = 1;
                        Smile.Opacity = 0;
                        ShoulderLeft.Opacity = 1;
                        ShoulderRight.Opacity = 1;
                        UpperArmLeft.Opacity = 1;
                        UpperArmRight.Opacity = 1;
                        LowerArmLeft.Opacity = 1;
                        LowerArmRight.Opacity = 1;
                        HandLeft.Opacity = 1;
                        HandRight.Opacity = 1;
                        UpperBody.Opacity = 1;
                        LowerBody.Opacity = 1;
                        ThighLeft.Opacity = 1;
                        ThighRight.Opacity = 1;
                        CalfLeft.Opacity = 1;
                        CalfRight.Opacity = 1;
                        FootLeft.Opacity = 1;
                        FootRight.Opacity = 1;
                        break;
                }
            }));
        }

        private void PlayMusic(String path)
        {
            Console.WriteLine("Now playing: " + path);
            this.Dispatcher.Invoke(new Action(() =>
            {
                if (path.Equals(""))
                {
                    music.Pause();
                }
                else
                {
                    music.Open(new Uri(path));
                    music.Play();
                }
            }));
        }

        private void ChangePuppet(String facePath, String shoulderLeftPath, String shoulderRightPath, String upperArmLeftPath, String upperArmRightPath, String lowerArmLeftPath, String lowerArmRightPath, String handLeftPath, String handRightPath, String upperBodyPath, String lowerBodyPath, String thighLeftPath, String thighRightPath, String calfLeftPath, String calfRightPath, String footLeftPath, String footRightPath)
        {
            this.Dispatcher.Invoke(new Action(() =>
            {
                face = new BitmapImage();
                face.BeginInit();
                face.UriSource = new Uri(facePath, UriKind.RelativeOrAbsolute);
                face.EndInit();
                ImageBehavior.SetAnimatedSource(Face, face);

                shoulderLeft = new BitmapImage();
                shoulderLeft.BeginInit();
                shoulderLeft.UriSource = new Uri(shoulderLeftPath, UriKind.RelativeOrAbsolute);
                shoulderLeft.EndInit();
                ImageBehavior.SetAnimatedSource(ShoulderLeft, shoulderLeft);

                shoulderRight = new BitmapImage();
                shoulderRight.BeginInit();
                shoulderRight.UriSource = new Uri(shoulderRightPath, UriKind.RelativeOrAbsolute);
                shoulderRight.EndInit();
                ImageBehavior.SetAnimatedSource(ShoulderRight, shoulderRight);

                upperArmLeft = new BitmapImage();
                upperArmLeft.BeginInit();
                upperArmLeft.UriSource = new Uri(upperArmLeftPath, UriKind.RelativeOrAbsolute);
                upperArmLeft.EndInit();
                ImageBehavior.SetAnimatedSource(UpperArmLeft, upperArmLeft);

                upperArmRight = new BitmapImage();
                upperArmRight.BeginInit();
                upperArmRight.UriSource = new Uri(upperArmRightPath, UriKind.RelativeOrAbsolute);
                upperArmRight.EndInit();
                ImageBehavior.SetAnimatedSource(UpperArmRight, upperArmRight);

                lowerArmLeft = new BitmapImage();
                lowerArmLeft.BeginInit();
                lowerArmLeft.UriSource = new Uri(lowerArmLeftPath, UriKind.RelativeOrAbsolute);
                lowerArmLeft.EndInit();
                ImageBehavior.SetAnimatedSource(LowerArmLeft, lowerArmLeft);

                lowerArmRight = new BitmapImage();
                lowerArmRight.BeginInit();
                lowerArmRight.UriSource = new Uri(lowerArmRightPath, UriKind.RelativeOrAbsolute);
                lowerArmRight.EndInit();
                ImageBehavior.SetAnimatedSource(LowerArmRight, lowerArmRight);

                handLeft = new BitmapImage();
                handLeft.BeginInit();
                handLeft.UriSource = new Uri(handLeftPath, UriKind.RelativeOrAbsolute);
                handLeft.EndInit();
                ImageBehavior.SetAnimatedSource(HandLeft, handLeft);

                handRight = new BitmapImage();
                handRight.BeginInit();
                handRight.UriSource = new Uri(handRightPath, UriKind.RelativeOrAbsolute);
                handRight.EndInit();
                ImageBehavior.SetAnimatedSource(HandRight, handRight);

                upperBody = new BitmapImage();
                upperBody.BeginInit();
                upperBody.UriSource = new Uri(upperBodyPath, UriKind.RelativeOrAbsolute);
                upperBody.EndInit();
                ImageBehavior.SetAnimatedSource(UpperBody, upperBody);

                lowerBody = new BitmapImage();
                lowerBody.BeginInit();
                lowerBody.UriSource = new Uri(lowerBodyPath, UriKind.RelativeOrAbsolute);
                lowerBody.EndInit();
                ImageBehavior.SetAnimatedSource(LowerBody, lowerBody);

                thighLeft = new BitmapImage();
                thighLeft.BeginInit();
                thighLeft.UriSource = new Uri(thighLeftPath, UriKind.RelativeOrAbsolute);
                thighLeft.EndInit();
                ImageBehavior.SetAnimatedSource(ThighLeft, thighLeft);

                thighRight = new BitmapImage();
                thighRight.BeginInit();
                thighRight.UriSource = new Uri(thighRightPath, UriKind.RelativeOrAbsolute);
                thighRight.EndInit();
                ImageBehavior.SetAnimatedSource(ThighRight, thighRight);

                calfLeft = new BitmapImage();
                calfLeft.BeginInit();
                calfLeft.UriSource = new Uri(calfLeftPath, UriKind.RelativeOrAbsolute);
                calfLeft.EndInit();
                ImageBehavior.SetAnimatedSource(CalfLeft, calfLeft);

                calfRight = new BitmapImage();
                calfRight.BeginInit();
                calfRight.UriSource = new Uri(calfRightPath, UriKind.RelativeOrAbsolute);
                calfRight.EndInit();
                ImageBehavior.SetAnimatedSource(CalfRight, calfRight);

                footLeft = new BitmapImage();
                footLeft.BeginInit();
                footLeft.UriSource = new Uri(footLeftPath, UriKind.RelativeOrAbsolute);
                footLeft.EndInit();
                ImageBehavior.SetAnimatedSource(FootLeft, footLeft);

                footRight = new BitmapImage();
                footRight.BeginInit();
                footRight.UriSource = new Uri(footRightPath, UriKind.RelativeOrAbsolute);
                footRight.EndInit();
                ImageBehavior.SetAnimatedSource(FootRight, footRight);
            }));
        }

        private void ChangeScene(String backgroundPath, String powerPath)
        {
            this.Dispatcher.Invoke(new Action(() =>
            {
                background = new BitmapImage();
                background.BeginInit();
                background.UriSource = new Uri(backgroundPath, UriKind.RelativeOrAbsolute);
                background.EndInit();
                ImageBehavior.SetAnimatedSource(Background, background);

                if (powerPath.Equals(""))
                {
                    power = new BitmapImage();
                    power.BeginInit();
                    power.UriSource = new Uri(@"/Images/I/Fire.gif", UriKind.RelativeOrAbsolute);
                    power.EndInit();
                    ImageBehavior.SetAnimatedSource(PowerLeft, power);

                    power = new BitmapImage();
                    power.BeginInit();
                    power.UriSource = new Uri(@"/Images/II/LaserLeft.gif", UriKind.RelativeOrAbsolute);
                    power.EndInit();
                    ImageBehavior.SetAnimatedSource(PowerLeft2, power);

                    power = new BitmapImage();
                    power.BeginInit();
                    power.UriSource = new Uri(@"/Images/III/15.png", UriKind.RelativeOrAbsolute);
                    power.EndInit();
                    ImageBehavior.SetAnimatedSource(PowerLeft3, power);

                    power = new BitmapImage();
                    power.BeginInit();
                    power.UriSource = new Uri(@"/Images/IV/15.png", UriKind.RelativeOrAbsolute);
                    power.EndInit();
                    ImageBehavior.SetAnimatedSource(PowerLeft4, power);

                    power = new BitmapImage();
                    power.BeginInit();
                    power.UriSource = new Uri(@"/Images/VI/Fire.gif", UriKind.RelativeOrAbsolute);
                    power.EndInit();
                    ImageBehavior.SetAnimatedSource(PowerLeft6, power);
                }
                else
                {
                    power = new BitmapImage();
                    power.BeginInit();
                    power.UriSource = new Uri(powerPath, UriKind.RelativeOrAbsolute);
                    power.EndInit();
                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transfer.mp3");
                    Thread.Sleep(1000);
                    ImageBehavior.SetAnimatedSource(PowerLeft, power);
                    ImageBehavior.SetAnimatedSource(PowerLeft2, power);
                    ImageBehavior.SetAnimatedSource(PowerLeft3, power);
                    ImageBehavior.SetAnimatedSource(PowerLeft4, power);
                    ImageBehavior.SetAnimatedSource(PowerLeft6, power);
                }
            }));
        }

        private void ChangeBackground(string url)
        {
            this.Dispatcher.Invoke(new Action(() =>
            {
                try
                {
                    var image = new BitmapImage();
                    int BytesToRead = 100;

                    WebRequest request = WebRequest.Create(new Uri(url, UriKind.Absolute));
                    request.Timeout = -1;
                    WebResponse response = request.GetResponse();
                    Stream responseStream = response.GetResponseStream();
                    BinaryReader reader = new BinaryReader(responseStream);
                    MemoryStream memoryStream = new MemoryStream();

                    byte[] bytebuffer = new byte[BytesToRead];
                    int bytesRead = reader.Read(bytebuffer, 0, BytesToRead);

                    while (bytesRead > 0)
                    {
                        memoryStream.Write(bytebuffer, 0, bytesRead);
                        bytesRead = reader.Read(bytebuffer, 0, BytesToRead);
                    }

                    image.BeginInit();
                    memoryStream.Seek(0, SeekOrigin.Begin);
                    image.StreamSource = memoryStream;
                    image.EndInit();
                    playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Transfer.mp3");
                    Thread.Sleep(1000);
                    ImageBehavior.SetAnimatedSource(Background, image);
                } catch (Exception ex)
                {
                    Console.WriteLine(ex.ToString());
                }
            }));
        }

        private void StartRecord()
        {
            // To start xbox control panel
            SendKeys.SendWait("^g");
            Thread.Sleep(1000);
            // Start recording
            SendKeys.SendWait("%s");
        }

        private void StopRecord()
        {
            SendKeys.SendWait("%s");
        }

        private int TCPServer()
        {
            IPAddress ip = Dns.GetHostEntry("localhost").AddressList[0];
            TcpListener server = new TcpListener(ip, 8080);
            TcpClient client = default(TcpClient);

            try
            {
                server.Start();
                Console.WriteLine("Server started...");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }

            while (true)
            {
                client = server.AcceptTcpClient();
                NetworkStream stream = client.GetStream();
                byte[] receivedBuffer = new byte[100];
                stream.Read(receivedBuffer, 0, receivedBuffer.Length);
                int count = 0;

                StringBuilder stringBuilder = new StringBuilder();

                foreach (byte b in receivedBuffer)
                {
                    if (b.Equals(0))
                    {
                        break;
                    }
                    else
                    {
                        count++;
                    }
                }

                string msg = Encoding.UTF8.GetString(receivedBuffer, 0, count);

                if (msg.Length < 5)
                {
                    if (msg.Substring(0, 1).Equals("/"))
                    {
                        LanguageProcessing(msg.Remove(0, 1));
                    }
                    else if (msg.Substring(0, 1).Equals("*"))
                    {
                        playMusicDelegate.Invoke(@"D:\Testing\puppet-based-digital-theater\Audios\Wrong.mp3");
                    }
                    else if (msg.Substring(0, 1).Equals("-"))
                    {
                        changeDialogueDelegate.Invoke("");
                    }
                    else
                    {
                        changeDialogueDelegate.Invoke("0");
                        showDialogueDelegate.Invoke(msg);
                    }
                }
                else
                {
                    if (msg.Substring(0, 5).Equals("https"))
                    {
                        showMagicDelegate.Invoke(4);
                        changeBackgroundDelegate.Invoke(msg);
                    }
                    else if (msg.Substring(0, 1).Equals("/"))
                    {
                        LanguageProcessing(msg.Remove(0, 1));
                    }
                    else
                    {
                        changeDialogueDelegate.Invoke("0");
                        showDialogueDelegate.Invoke(msg);
                    }
                }
            }

            return 0;
        }

        private void StartAni(String message, String bgcolor, double duration)
        {
            ResponseBar.Text = message;
            ResponseBar.Background = (SolidColorBrush)(new BrushConverter().ConvertFrom(bgcolor));

            DoubleAnimation fadeinAnimation = new DoubleAnimation(0.05, 1, new Duration(TimeSpan.FromSeconds(duration)));
            DoubleAnimation holdAnimation = new DoubleAnimation(1, 1, new Duration(TimeSpan.FromSeconds(1.25)));
            DoubleAnimation fadeoutAnimation = new DoubleAnimation(1, 0, new Duration(TimeSpan.FromSeconds(duration)));

            Storyboard fadeinStotyboard = new Storyboard();
            fadeinStotyboard.Children.Add(fadeinAnimation);
            Storyboard.SetTarget(fadeinStotyboard, ResponseBar);
            Storyboard.SetTargetProperty(fadeinStotyboard, new PropertyPath("(UIElement.Opacity)"));

            Storyboard holdStotyboard = new Storyboard();
            holdStotyboard.Children.Add(holdAnimation);
            Storyboard.SetTarget(holdStotyboard, ResponseBar);
            Storyboard.SetTargetProperty(holdStotyboard, new PropertyPath("(UIElement.Opacity)"));

            Storyboard fadeoutStotyboard = new Storyboard();
            fadeoutStotyboard.Children.Add(fadeoutAnimation);
            Storyboard.SetTarget(fadeoutStotyboard, ResponseBar);
            Storyboard.SetTargetProperty(fadeoutStotyboard, new PropertyPath("(UIElement.Opacity)"));


            fadeinStotyboard.Completed += (obj, args) =>
            {
                holdStotyboard.Begin();
            };
            holdStotyboard.Completed += (obj, args) =>
            {
                fadeoutStotyboard.Begin();
            };
            fadeoutStotyboard.Completed += (obj, args) =>
            {
            };
            fadeinStotyboard.Begin();
        }

        private void FadeOutAnimation(int seconds)
        {
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(seconds));
            doubleAnimation.From = 0.7;
            doubleAnimation.To = 0.0;
            Dialogue.BeginAnimation(OpacityProperty, doubleAnimation);
        }
    }
}