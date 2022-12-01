# Library System written in C++
This is a Library System application created with C++. 
Different from my most recent project <a href = "https://github.com/phamduylong/LoginSystem" target = "blank">(here)</a>, 
I decided to try the OOP approach for this project with a combination of a Book class and a Singleton pattern namespace called as Library.<br> 
Library has only one instance playing the role of a database/data container in this program to help transferring data from user to file and vice versa 
It worked out pretty well for me and the program is a bit less bug-prone.<br>
However, this project has its limits. One major limit is all the data is saved in a form of a CSV (Comma Separated Value) file, which is actually used for dataset, mostly.<br>
In order to use the project, please download all the files from project (.cpp and .h files if you're using any other IDE but Microsoft's Visual Studio) or clone it from GitHub. 
If you are using JetBrains CLion, please move the file <em>db.txt</em> into <em>cmake-build-debug</em> folder of the project to prevent bugs.
<br> The program has internal instructions itself, with a menu of functions and error messages if an error occured during the run. 
<br>
I am open to any kind of feedbacks/comments/contributions. Hit me up with social media links above or through email preferably 😌
