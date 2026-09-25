# Arduino Zombie Game

以 Arduino 與 ILI9341 TFT 彩色螢幕實作的 2D 動態遊戲原型。專案將角色圖像以 `PROGMEM` 常數陣列儲存在 Flash，避免大量圖片資料佔用有限的 SRAM，再透過 SPI 將畫面繪製到 TFT。主要程式為 `zombie_loli.ino`。

## 技術實作

- **顯示驅動**：使用 `Adafruit_GFX` 與 `Adafruit_ILI9341` 函式庫，透過 SPI 控制 ILI9341 顯示器；程式明確定義 CLK、MISO、MOSI、DC、CS 與 RST 腳位。
- **圖像資料**：以單色 bitmap 陣列儲存角色素材，執行時由 Arduino 直接讀取 Flash 並渲染，適合記憶體受限的嵌入式環境。
- **遊戲畫面**：以逐幀更新方式處理畫面，將角色、背景與狀態呈現在 TFT 螢幕上，練習嵌入式圖形輸出與即時互動程式設計。

## 使用方式

1. 在 Arduino IDE 安裝 `Adafruit GFX`、`Adafruit ILI9341` 函式庫。
2. 依程式中的腳位定義接上 ILI9341 TFT 螢幕。
3. 開啟並上傳 `zombie_loli.ino`。

本專案著重 Arduino 圖形顯示、Flash 記憶體運用與互動式遊戲邏輯的練習。
