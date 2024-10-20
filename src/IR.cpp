#include <Arduino.h>

class IR {
  private:
    int pin;            // Pin where the IR sensor is connected
    uint8_t irdata;     // Data received
    int ir_repeat_cnt;  // Repeat count for IR signal

  public:
    IR(int pin) {
      this->pin = pin;
      pinMode(pin, INPUT);
      irdata = 0xFE;
      ir_repeat_cnt = 0;
    }

    uint8_t GetIR() {
      if (digitalRead(pin) == LOW) {
        ir_repeat_cnt = 0;
        int count = 0;

        // Wait until the signal rises to HIGH (initial pulse)
        while (digitalRead(pin) == LOW) {
          count++;
          delayMicroseconds(30);  // Delay for 30 microseconds
        }

        // Wait until the signal falls to LOW, count up to 160
        count = 0;
        while (digitalRead(pin) == HIGH && count < 160) {
          count++;
          delayMicroseconds(30);
        }

        // Reading the bits of the IR signal (32 bits)
        uint8_t data[4] = {0, 0, 0, 0};
        int idx = 0, cnt = 0;
        
        for (int i = 0; i < 32; i++) {
          // Wait for the signal to go LOW (start of next bit)
          count = 0;
          while (digitalRead(pin) == LOW && count < 30) {
            count++;
            delayMicroseconds(30);
          }

          // Measure how long the signal stays HIGH
          count = 0;
          while (digitalRead(pin) == HIGH && count < 80) {
            count++;
            delayMicroseconds(30);
          }

          // If the HIGH pulse was long enough, it's a 1, otherwise it's a 0
          if (count > 35) {
            data[idx] |= (1 << cnt);
          }

          // Adjust data indices
          if (cnt == 7) {
            cnt = 0;
            idx++;
          } else {
            cnt++;
          }
        }

        // Check the integrity of the data
        if (data[0] + data[1] == 0xFF && data[2] + data[3] == 0xFF) {
          irdata = data[2];  // Valid data
        }

      } else {
        // Repeat count check
        if (ir_repeat_cnt > 110) {
          ir_repeat_cnt = 0;
          irdata = 0xFE;  // Reset when there are too many repetitions
        } else {
          delay(1);  // Delay for 1 ms
          ir_repeat_cnt++;
        }
      }

      // Return the captured data if valid
      if (irdata != 0xFE) {
        return irdata;
      } else {
        return 0xFE;  // No data captured
      }
    }
};

// The code above is generated from the code below by using ChatGPT
/*
class ir():
    def __init__(self):
        self.Pin = Pin(7)
        self.Pin.value(1)
        self.ir_repeat_cnt = 0
        self.irdata = 0xfe
            
    def Getir(self):
        if self.Pin.value() == 0:
            
            self.ir_repeat_cnt = 0
            count = 0
            while self.Pin.value() == 0:
                count += 1
                time.sleep(0.00003)

            count = 0
            while self.Pin.value() == 1 and count < 160:
                count += 1
                time.sleep(0.00003)
            #print("")
            idx = 0
            cnt = 0
            data = [0,0,0,0]
            for i in range(0,32):
                count = 0
                while self.Pin.value() == 0 and count < 30:
                    count += 1
                    time.sleep(0.00003)

                count = 0
                while self.Pin.value() == 1 and count < 80:
                    count += 1
                    time.sleep(0.00003)

                if count > 35:
                    data[idx] |= 1<<cnt
                if cnt == 7:
                    cnt = 0
                    idx += 1
                else:
                    cnt += 1
            
            if data[0]+data[1] == 0xFF and data[2]+data[3] == 0xFF:
                self.irdata = data[2]
        else:
            if self.ir_repeat_cnt > 110: 
                self.ir_repeat_cnt = 0
                self.irdata = 0xfe
            else:
                time.sleep(0.001)
                self.ir_repeat_cnt += 1
        if self.irdata != None:
            if self.irdata != 254:
                return self.irdata
*/

//It is from this repository:
//https://github.com/YahboomTechnology/Pico-Robot/blob/main/Appendix/Library/pico_car.py