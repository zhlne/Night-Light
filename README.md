# 🌙 Arduino 光控夜燈系統 (Night Light with Light Sensor)

本專案為一個基於 Arduino 的光控夜燈系統，能根據環境光線強度自動開關 LED 燈，並透過 I2C LCD 顯示光照數值與狀態（白天/夜晚）。

## ✅ 功能特色

- 使用光敏電阻讀取環境亮度  
- 自動判斷白天與夜晚（可調閾值）  
- 夜晚時自動亮燈，白天時自動關燈  
- LCD 實時顯示光線強度與系統狀態  
- 串列監控列印光照值，方便除錯與測試  

## 📦 使用到的函式庫

- `Wire.h`：I2C 通訊支援  
- `LiquidCrystal_I2C.h`：控制 LCD 顯示  

## 💡 程式邏輯簡介

```cpp
if (lightLevel < lightThreshold) {
    // 光線低於閾值 → 判斷為夜晚，開燈
    digitalWrite(ledPin, HIGH);
    lcd.print("Night: LED ON");
} else {
    // 光線高於閾值 → 判斷為白天，關燈
    digitalWrite(ledPin, LOW);
    lcd.print("Day: LED OFF");
}
```
