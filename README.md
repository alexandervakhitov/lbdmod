# lbdmod

A line detection & description pipeline based on the EDLines detector and LBD descriptor in the OpenCV implementation.

To use, please 

1. Install dependencies (gcc, OpenCV, for the python wrapper also Python and boost)

2. Customize the CMakeLists.txt, part with Python paths (provide paths to the python and numpy libraries and headers)

3. Use (under Linux)
```
cmake .
make
sudo make install
``` 
Then the library will be built in the root folder, and the wrapper will be installed to the Python *dist-packages* folder.

You can check that it works by running
```
./lbd_mod_test
``` 
from the same folder. After the execution, the file 'test.png' with line detection visualization should appear in this folder.
