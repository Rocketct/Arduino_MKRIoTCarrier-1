#ifndef ARDUINO_MKRIoTCarrier_Qtouch
#define ARDUINO_MKRIoTCarrier_Qtouch

#include "Arduino.h"
#include "Arduino_Qtouch.h"


//manager
class MKRIoTCarrier_Qtouch_Manager{
    public:
    MKRIoTCarrier_Qtouch_Manager(); 

    bool rtcflag = false;
    
        
    bool begin();
    void update();

    int t_state[5];

    private:


};

class MKRIoTCarrier_Qtouch{
    public:
    MKRIoTCarrier_Qtouch(int padIndex, MKRIoTCarrier_Qtouch_Manager * pManager); //Individual
    

    bool getTouch();
    bool onTouchDown();
    bool onTouchUp();
    bool onTouchChange();
    
    //Set touch settings
    
    void updateConfig(int newSens);

    private:
    
    MKRIoTCarrier_Qtouch_Manager  * _pManager;
    int _padIndex;  

    bool _touches[10];                //To know last touches

    void _saveToHistory(bool newEntry);

    //Cfg
    bool setOnChange = false;       //Touch on change
    bool setOnNormal = false;       //Allways read
    bool setOnUp = false;           //When the pad is not being touched
    bool setOnDown = false;         //When is pressed, to make 2 Downs you need to touch it, release it and touch it again

};

#endif