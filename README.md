
# Testing ZMK Firmware on cheap Green-Blackpill STM32F401CCU6

![image](https://user-images.githubusercontent.com/95753855/147224400-07c82a33-d80b-4757-b311-69117fd78a8d.png)

## Log 23/12/21
- The [tinyuf2 bootloader](https://github.com/Deemen17/zmk-config-blackpill_f401/tree/main/tinyuf2_bootloader_stm32f401_blackpill) works perfectly
- Still have problem with the ZMK: flashed well but it can't boot as hid device

## Log 24/12/21
- Edited some code from [megamind4089's suggestion](https://gist.github.com/megamind4089/43ae5e3eb13022c0ce395161c7640e4b), ZMK works well as hid device now
- Trying some change to work with Sesame PCB rev. 1
  
## Log 25/12/21 - Merry Christmas!
- The stm32f401 blackpill is running ZMK on Sesame PCB rev. 1 smoothly!
- Testing the [nickcoutsos's keymap editor](https://github.com/nickcoutsos/keymap-editor)
