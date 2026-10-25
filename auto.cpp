#include <windows.h>
#include <iostream>
#include<chrono>
#include<immintrin.h>
using namespace std;
using namespace std::chrono;
const int TARGET_CLICKS = 1000; // Change to your desired number of clicks
const int DELAY_MS = 0;      // Delay between clicks in milliseconds

void DoClick() {
    INPUT inputs[2] = {};
    // Left button down
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    // Left button up
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    
    SendInput(2, inputs, sizeof(INPUT));
}

int main() {
    std::cout << "Ultra-lean Clicker ready. Press 'B' to do " << TARGET_CLICKS << " clicks. Press ESC to quit.\n";
    
    while (true) {
        // Exit if ESC is pressed
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }
       
        // Trigger on 'B' key
        if (GetAsyncKeyState('B') & 0x8000) {
            int clicked = 0;
            std::cout << "Starting clicks...\n";
             auto start = high_resolution_clock::now();
            while (clicked < TARGET_CLICKS) {
                // Emergency stop if ESC is pressed mid-click
                if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                	
                	
                    std::cout << "Aborted!\n";
                    break;
                }
                
                DoClick();
                clicked++;
                
            }
            auto end  = high_resolution_clock::now();
           	auto duration = duration_cast<milliseconds>(end - start);
            std::cout<<"time taken for "<<TARGET_CLICKS<<" clicks = " << duration.count()<<"\n";
            std::cout << "Finished " << clicked << " clicks.\n";
          
           
        }
        
        Sleep(10); // 
    }
    
    return 0;
}

