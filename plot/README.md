# Button test plots

## Installation and Usage

Install Flexiplot for nice Serialplots (based on Qt and qmake)

```bash
sudo apt update
sudo apt install qt5-default qt5-qmake qtbase5-dev-tools qt5-doc 

# dependencies
sudo apt install libqt5charts5-dev libqt5serialport5-dev libqt5svg5-dev

git clone https://github.com/xcoder123/FlexiPlot
cd FlexiPlot
qmake && make
# now run it
./FlexiPlot
```
Now in FlexiPlot choose port and baudrate (115200), then flash microcontroller using (here) arduino ide or `arduino-cli` command line tool

