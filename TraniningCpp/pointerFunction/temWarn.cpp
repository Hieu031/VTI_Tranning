#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

typedef void (*sensorCallback)(int);

void EngineTemperatureWarning(int temperature); //function warning when temperature so high
void EngineTemperatureNormal(int temperature); //function notific normal
void ProcessSensorEvent(int temperature, sensorCallback callback); //handle event

int main(){
    int n = 10;
    while (n--)
    {
        //Initialize seed for random
        srand(static_cast<unsigned int> (time(0)));

        //assuming measure temperature from sensor
        int temperature = rand() % 120;

        cout << "Thetemperature current of Engine: " << temperature << " °C." << endl;

        //Define function pointer to save function manage suitable
        sensorCallback callback = nullptr;

        //Set condition to warning 
        if(temperature > 90){
            callback = EngineTemperatureWarning;
        }else{
            callback = EngineTemperatureNormal;
        }

        //Call function handle 
        ProcessSensorEvent(temperature, callback);
    }

    return 0;
}

void EngineTemperatureWarning(int temperature){
    cout << "Warning: the temperature is too high (" << temperature << " °C)! Let check immediately." << endl;
}

void EngineTemperatureNormal(int temperature){
    cout << "The temperature is normally: (" << temperature << " °C)." << endl;
}


void ProcessSensorEvent(int SensorValue, sensorCallback callback){
    callback(SensorValue);
}