# Crisper
Sub Project of a hopefully easy to use command line for multi user purposes.

- Start Date🕙: 30/06/2023.

-  Status: Compiles and works correctly - working on server commands now - adding user help module - also now beginning neural networks will do further testing and training locally however will take some time.

-----------

Matlabs Notes:
--
Image processing ideas:

- based on rgb values, use rgb values for pattern matching -> pattern match images to locations and images of locations with other data available in image (text,numbers, rgb color values , gradients of rgb values to determine categories such as time of image taken, skin pigmentation , etc to gain approximate geo location of images and infomation images provide. (need large amounts of training data for this tho).

- determine image quality, from image quality base classification probabilities on number of feature extractions, match features with trained images to gain probability of image being in relation to training data from matching inital features to trained images, find outliers between image and training images, try and classify and filter out outliers, try and branch to partial image feature relations with relations to other images from the input image values, additionally create grid of rgb values for pattern matching sections of images with other image, similar to lemmatisation, try to group found features which have relations with training sets, add additional training images based on input values into search engines and accessible databases to find and predict probability of image relations per grid section till a image which matches the input image is found, use image which is has a high probability of being similar enough to input image and gain infomation on the image online and from training data and use that as additional input features to evaliate with inital input featurs , also branch out from input features from image which relates online with other similar images and gain there infomation as such: 


- [InputImage] -> [classified features] -> [feature set as labels etc] -> [match with training data image features] ->[from training data image features] -> 

- [if image is not the same image continue] -> [gain probable relations between training images and input image] -> [from training images use additional 

- infomation from training images] -> [training infomation search for additional images which relate to classified name,location,place,etc] -> 

- [process images which arent in training data to be in training data (watch out for memory and storage issues) ] -> [new images classified and labelled appropiately] -> [match and relate new images with training images which relate to input image] -> [ if degree of probability is achieved , new training image paired with initial training 

- image and features extracted] -> [use additional features from new image and training to pattern match with initial image to find more feature relations] -> [once probability is high enough group images and related data with new image] -> [output images which relate high enough with input image with additional features] -> 


- [input data and scruitinise logically, for example if image is determined to be "image of person...", evaluate related data so we know people cant be above a certain height and data cant relate to a person unlogically without additonal related branches of data ,such as country size wont be valid unless data feature is related to place person lives , metrics have to be accurate for classified data] -> [output infomation on input image].


Post processing adjustments: 

-
-
-

fail/success cases:

- memory issues handling : 
- low probability issues :
- image quality :
- formatting : 



sentimental analysis training and preprocessing is finished, preprocessing for NMT is finished however needs further optimisation as matlabs doesnt support sequence to sequence machine translation training i am currently making custom batching and training loops as well as custom sequence classification layers etc, still optimising sentiment training for better results.


sentiment analysis preprocessing:

-
-
-


Capturing sentiment steps and context Logic : 

-
-
-



sentiment analysis training :

-
-
-





sentiment analysis datasets being used:

-
-
-

XTrain and YTran formating :


- Padding sequence logic :


- Layers used: [ 


  ]; 

results analysis and accuracy logic:

-
-
-
------------


NMT preprocessing Logic :

-
-
-

NMT Training:

-
-

Nmt custom functions and classes : 

-
-


XTrain and YTrain formatting logic:



- Padding sequence logic :
-
-
-
-


XTrain(language one) format and logic :

-
-
-



YTrain(language two) format and logic : 

-
- 


Target sequence and input features: 

-
-



- Layers used : [ 




  ]; 


results analysis and accuracy logic:

-
-
-

Variants of attention layers (considered for optimisation) :

ie: ScaledDotProductAttentionLayer. - sentiment analysis training.




Dataset used: 

- more will be added
- english-german


Matlabs addons: 

-
-
-
-
-

matlabs documentation used:

-
-
-
-

Literature used : 

-
-
-

------------------

Python for data science use cases:

-
-
-
-

Python Libs:

-
-
-
-
-
-


Dependencies: 

-
-
-

installation versions:

-
-
-
-

command lines for dependencies if not handled already by function-s:

-
-
-
-


--------------




- Organising into payloads for specific use cases operating systems , web browsers , specific environments.

- This is a long term project im constantly working on when i can, at the moment im using matlabs to gather the results for assessing what models will be efficent for each task i will be applying each model's use case for.

- end date is unknown however during my free time this project will constantly be expanded upon till its good enough for others to contribute upon my inital ideas and implementation.

- Creating branches for experimentation. 
- My other project ideas and repos will be integrated into this project.
- Need to start mapping control flow and organise files.
- polished threads handling user input , adding server commands.


- Useful note worth exploring in my journey of this project would also be advancements in hearing aids / hearing assistance through the use of neural networks in exploring and achieving natural sound for those with hearing impairments which would garner a side project when i come to explore this side topic in relation to consumer accessible hearing devices with neural calibration or other ideas involving neural networks in audio translation , i understand this already exists however i wish to also explore this topic of interest and try and contribute to this area of development.
- possibly could try to find better ways to reduce costs throughout the manufacturing process with more efficient techniques and further pursuit of incorporating ai and technological advancements.

----------------------------
Diagrams of neural variants : 



---------------------------------
Branch List:
---
- Server Branch:
------------------------------------------------------
Modules List & Sub Modules
--

-
-
-
-
-
-

-------------------------------------------------------
Server functionality and commands added (33 commands so far)
--
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-

Server Helper functions:

-
-
-

Server Thread modules:

-
-
-
 
Server Thread Logic:

-
-
-


--------------------------------------------------------
Goals
-----

- make extensive server commands work correctly.
- make commands use polymorphism instead of the dirty if chain.
- leading onto oop optimisation of commands for easier maintainability and scalability.
-
- 
-------------------------------------------------------------------------
Updates
---

RoadMap (Currently not in order needs further details) :
  1.  Finish and refine server logic.
  2.  Add server commands.
  3.  Integrate further thread handling.
  4.  Add additional needed libraries.
  5.  Add dependency check functionality , automate some dependencies.
  6.  Finish validation and make it dynamic , integrate hash encryption.
  7.  Structure Files.
  8.  Setup Database.
  9.  Add Neural network integration.
  10.
  11.
  12.
  13.
  14.

- 1. Work status (meaning when ill specifically be actively working on this project) : Break while i finish matlabs anlaysis for model efficency at given tasks.

--------
Neural network model variants being considered (matlabs , API's)
--

[ Reasons for each variant (pros & cons) ]

==================CNS====================
- 1. Details: 
- 2. Pros + Use Case:
- 3. Cons + possible draw backs of use : 


===============RNN=======================

- 1. Details: 
- 2. Pros + Use Case:
- 3. Cons + possible draw backs of use : 

==============HYBRID VARIANTS===============

Hybrid models is where i will integrate multiple layers of different models as well as encoding techniques , decoding , back prop + calibration.
Additionally ill list each hybrid model being considered after inital models are documented and testing has began.

- 1. Details: 
- 2. Pros + Use Case:
- 3. Cons + possible draw backs of use : 


-----------------------

FORMS OF NEURAL NETWORKS:

I am aware that machine translation accuracy for non latin language sets is biased and inaccurate especially chinese and japenese characters and understanding/interpretation of meaning , meaning through word2vec tokenization etc. 

- Machine Translation(trained on large data sets) : for user input , language corpus sets for universal use based on users language.

- Image Processing(Process large sets of image based data) : for enhanced accuracy of target enviroment + additional infomation.

- LSTM VARIANTS (sequential data) : for processing request times , response analysis (signal processing) , pattern recognition of enviroment behaviour.

--------------
ISSUES REGARDING PROCESSING POWER AND NEURAL NETWORK CLOUD HOSTING (Future concerns)


- Google cloud hosting?
- before the botnet is eventually made and operational, drawing and utilizing processing power and efficency is of upmost importance 

- will need additional road map for this.

- Neural network Obfuscated hosting and interaction:


-----------------------------
As i understand neural networks are rather complex they will require additional sub road maps during this project.

------------------
Data Preprocessing Logic:
--
[preprocessing Steps]

-
- 
- 
-
-
-
-

[Batch Size & Processing optimisations:]

- [Ideas]:
  
1.
2.
3.

Specific model fomatting:

-
-
-

HelperFunctions Logic: 

- 1
- 2 
- 3
- 4
- 5 
- 6

Optimization features:

-
- 
-

Neural network Sub Road Map:
-------------------------------
[Start]
- Data collection: 
- Model Training and adaption techniques:
-
-
-
-
[End]

---------------------
Payloads Section
--

Mapped payloads to specific enviroments:



[OS] : 


-- Unix Systems -- 

  Distributions:


  - Linux distros -- 
  
 - Ubuntu - > versions.
 - Parrot os - > versions.
 -
 -
 -
 

  Archs:
  
 -
 -
 -


 -- Windows -- 

[Windows 11]

-
-

[Windows 10]

Versions:

-
-
-
-

Features of windows 10 which can be exploited [version specific] :

-
-
-
-

Payload mechanisms:

-
-

Payload Features:

-
-

- Process allocation techniques:

-
-


- Evasion:

-
-
- 

Known CSV's:

- 1:

[Year] :

[Enviroment]: 

[Use case]:


- 2:

[Year] :

[Enviroment]:

[Use case:]


[could provide a database model and link to show all csv's being used]

-excel 

-
---------------
Dependencies
----
- C++ version : std 14
---------------
Debug Analysis:
---
- Control Flow: [] -> -> -> -> []

- Unexpected Behaviour: None.

- RoadBlocks/Issues: None currently.

-----------
Licenses
----

- Being decided will be updated at a later date.

-------------------------------------------------------------------------------------------------
![CRISPER2](https://raw.githubusercontent.com/indirectDirectEnumeration69/Crisper/main/CRISPER2.png)


