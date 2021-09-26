#include <NESController.h>

#define SER 13
#define LATCH 12
#define CLK 11

NESController NESCtrl(SER, CLK, LATCH);

void setup() {
  Serial.begin(9600);
  NESCtrl.init();
}


void loop() {
  NESCtrl.update();
//  oneLineDisp();
  fancyDisp();

  delay(50);
}

void fancyDisp() {
  Serial.println("\n\n");
  Serial.println("    [" + String(NESCtrl.isPressed(NESCTRL_UP) ? "^" : " ") + "]");
  Serial.println(" [" + String(NESCtrl.isPressed(NESCTRL_LEFT) ? "<" : " ") + "]   [" + String(NESCtrl.isPressed(NESCTRL_RIGHT) ? ">" : " ") + "]");
  Serial.println("    [" + String(NESCtrl.isPressed(NESCTRL_DOWN) ? "v" : " ") + "]      [" + String(NESCtrl.isPressed(NESCTRL_SELECT) ? "SELECT" : "      ") + "] [" + String(NESCtrl.isPressed(NESCTRL_START) ? "START" : "     ") + "]\   [" + String(NESCtrl.isPressed(NESCTRL_B) ? "B" : " ") + "] [" + String(NESCtrl.isPressed(NESCTRL_A) ? "A" : " ") + "]");
}


const String buttons[] = {"A", "B", "Select", "Start", "Up", "Down", "Left", "Right"};
void oneLineDisp() {
  //Serial.println(NESCtrl.getRawData(), BIN);

  String txt = "";
  for (unsigned int i = 0; i < 8; ++i) {
    txt += "[";
    if (NESCtrl.isPressed(i))
      txt += buttons[i];
    else {
      for (unsigned int j = 0; j < buttons[i].length(); ++j)
        txt += " ";
    }
    txt += "] ";
  }
  Serial.print(txt);
  Serial.write('\r');
}

