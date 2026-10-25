# Ultra-High Performance C++ Auto Clicker (8,000+ CPS)

A highly optimized, lightweight, and low-latency input simulation tool written in native C++. By leveraging low-level Windows APIs and bypassing standard OS loop bottlenecks, this engine achieves **8,000+ Clicks Per Second (CPS)**. 

This repository serves as a technical demonstration of high-performance C++ engineering, multi-threading, and precision benchmarking.

---

## ⚡ Performance & Benchmarking

To prove the efficiency of the execution loop, the click throughput is benchmarked using microsecond-accurate precision via `<chrono>`. 

### Chrono Benchmark Results
*Place your benchmark console screenshot here to show off the metal code metrics!*

---

## 🚀 Technical Highlights & Optimizations

* **Native Win32 API Integration:** Utilizes high-efficiency hardware input simulation via `SendInput` rather than slower legacy functions.
* **Microsecond Precision:** Loop timing and metrics are managed via `std::chrono::high_resolution_clock` to prevent resource starvation while maintaining maximum throughput.
* **Minimal Overhead:** Zero unnecessary allocations in the execution hot-path, allowing the processor to blast inputs at bare-metal speeds.

---

## ⚠️ The Ultimate Loop Flex: UI Thread Starvation

This engine injects hardware events faster than standard application event loops can clear them. 

When targeted at web-based click tests, the tool will completely saturate the browser's main JavaScript thread. Because the browser chokes trying to process the massive queue of DOM updates (thousands of clicks per second), the page will instantly freeze or become unresponsive. 

This isn't a bug—it's a demonstration of bare-metal C++ bypassing application-layer bottlenecks.

---

## 🛠️ How to Compile & Run

Because high-speed input tools can trigger false positives in pre-compiled binaries, **this project must be compiled from source**.

1. Clone the repository:
   ```bash
   git clone https://github.com
   ```
2. Open the project in **Visual Studio** (or your preferred C++ IDE).
3. Ensure the build configuration is set to **Release** mode with optimizations enabled (`/O2`).
4. Build and run the solution.

---

## ⚠️ Disclaimer & Educational Notice

**This project is created strictly for educational, engineering, and performance-benchmarking purposes.** 

* **Use at your own risk.** Blasting 8,000 CPS can easily freeze UI threads, crash legacy applications, or cause unintended OS behavior if left unchecked.
* **Anti-Cheat Warning:** Running this tool alongside modern video games will likely trigger automated anti-cheat systems (e.g., Vanguard, Easy Anti-Cheat) and result in permanent account or hardware bans. 
* The author is not responsible for any damage, data loss, or platform bans resulting from the use or misuse of this source code.

---
THE BENCHMARKING IS DONE USING CHRONO IN MILLISECONDS AND NOT IN MICROSECONDS DUE TO THE FUNCTION CALL LATENCY <img width="1447" height="922" alt="image" src="https://github.com/user-attachments/assets/a6f003f9-52f6-4b46-b011-21dfa0597aa4" />
<img width="1918" height="1078" alt="Screenshot 2026-10-25 114818" src="https://github.com/user-attachments/assets/b2ab9dae-372f-454c-8d1e-352e12f473f6" />
<img width="1918" height="1078" alt="Screenshot 2026-10-25 114818" src="https://github.com/user-attachments/assets/21bf82f8-3ee6-4800-b74b-b9c015d00f49" />


## 📜 License

This project is licensed under the **MIT License** — feel free to use, modify, and study the code for personal and educational projects. See the `LICENSE` file for details.
