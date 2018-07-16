//  Author:Frankie.Chu 
//  Date:March 9,2012
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
/***************************************************************************/
#include "RGBdriver.h"
#define CLK 2//pins definitions for the driver        
#define DIO 3
RGBdriver Driver(CLK,DIO);
void setup()  
{ 

}  
void loop()  
{ 
  unsigned int i;
  while(1){
    for (int o = 0; o < 3; ++o) {
      for(i = 0;i < 256;i ++) {
        setColor(i, o);
        delay(10);
      }
      for(i = 255;i > 0;i --) {
        setColor(i, o);
        delay(10);
      }
    }
    for(i = 0;i < 256;i ++) {
      Driver.begin();
      Driver.SetColor(i,i,i);
      Driver.end();
      delay(10);
    }
    for(i = 255;i > 0;i --) {
      Driver.begin();
      Driver.SetColor(i,i,i);
      Driver.end();
      delay(10);
    }
  }
}

void setColor(uint8_t i, uint8_t o){
  Driver.begin(); // begin
  switch (o) {
    case 0:
      Driver.SetColor(i,0,0); //Red. First node data. SetColor(R,G,B)
      break;
    case 1:
      Driver.SetColor(0,i,0); //Green. First node data. SetColor(R,G,B)
      break;
    case 2:
      Driver.SetColor(0,0,i); //Blue. First node data. SetColor(R,G,B)
      break;
  }
  Driver.end();
}
