#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#include "ZedBoard.h"
#include "WiimoteAccel.h"

class WiimoteToLed : public WiimoteAccel{
      ZedBoard *zed_board;
      
      public:
             WiimoteToLed(ZedBoard *z1){
      
             zed_board = z1;
             }


void ButtonEvent(int code, int acceleration){

     cout << "Code = " << code << ", acceleration ="  << acceleration << endl;
     
     int a = abs(acceleration);
     
     if(code == 3){
     for (int i = 0; i < 8; i++) {
     zed_board->Write1Led(i, 0); 
     }
     if (a > 0 && a < 12){
         zed_board->Write1Led(0, 1);
         
         }
         
     else if (a > 12 && a < 24) {
         for (int i = 0; i < 2; i++){
             zed_board->Write1Led(i, 1);
             }
         }
         
     else if (a > 24 && a < 36) {
         for (int i = 0; i < 3; i++){
             zed_board->Write1Led(i, 1);
             }
         }
         
     else if (a > 36 && a < 48){
         for (int i = 0; i < 4; i++){
             zed_board->Write1Led(i, 1);
             }
         }
         
     else if (a > 48 && a < 60){
         for (int i = 0; i < 5; i++){
             zed_board->Write1Led(i, 1);
             }
         }
         
     else if (a > 60 && a < 72){
         for (int i = 0; i < 6; i++){
             zed_board->Write1Led(i, 1);
             }
         }
         
     else if (a > 72 && a < 84){
         for (int i = 0; i < 7; i++){
             zed_board->Write1Led(i, 1);
             }
         }
     
     else if (a > 84 && a < 100) {
        for (int i = 0; i < 8; i++) {
         zed_board->Write1Led(i, 1); 
         }
        }
     }
}
};
     

             
                                  
int main(){
    
    ZedBoard zed_board;
    
    WiimoteToLed wiimote_to_led(&zed_board);

    wiimote_to_led.Listen();

    return 0;

}