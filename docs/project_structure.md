# 🔧 Project Structure

```yaml
AitA/
├── .github
│   ├── CODE_OF_CONDUCT.md
│   └── CONTRIBUTING.md
├── .vscode
│   ├── settings.json
│   └── tasks.json
├── docs
│   ├── stm32_board
│   │   ├── stm32_board.md
│   │   ├── STM32_stm32f4discovery.pdf
│   │   └── STM32_UM1472-discovery-kit.pdf
│   ├── connect_to_usb_based_serial_ports.md
│   ├── dependencies.md
│   ├── project_structure.md
│   └── SUMMARY.md
├── scripts
│   ├── detect_serial_port.py
│   ├── doc_generate_project_structure.py
│   ├── setup_linux.sh
│   ├── setup_python.sh
│   ├── stm32f4_drivers_add_or_update_subs.sh
│   ├── stm32f4_remove_subs.sh
│   ├── stm32f4_templates_ll_add_or_update_sub.sh
│   ├── stm32_commands_runner.py
│   ├── unity_add_or_update_sub.sh
│   ├── unity_remove_sub.sh
│   └── unit_test_run.sh
├── stm32f4_prj
│   ├── core
│   │   ├── inc
│   │   │   ├── bsp.h
│   │   │   ├── command_processor.h
│   │   │   ├── main.h
│   │   │   ├── protocol.h
│   │   │   ├── stm32f4xx_hal_conf.h
│   │   │   ├── stm32f4xx_it.h
│   │   │   ├── stm32_assert.h
│   │   │   └── usart.h
│   │   └── src
│   │       ├── bsp.c
│   │       ├── command_processor.c
│   │       ├── main.c
│   │       ├── protocol.c
│   │       ├── startup_stm32f407vgtx.s
│   │       ├── stm32f4xx_it.c
│   │       ├── stubs.c
│   │       ├── syscalls.c
│   │       ├── sysmem.c
│   │       ├── system_stm32f4xx.c
│   │       └── usart.c
│   ├── drivers
│   │   ├── cmsis
│   │   │   ├── core
│   │   │   │   ├── CMSIS
│   │   │   │   │   └── Core
│   │   │   │   │       └── Include
│   │   │   │   │           ├── cachel1_armv7.h
│   │   │   │   │           ├── cmsis_armcc.h
│   │   │   │   │           ├── cmsis_armclang.h
│   │   │   │   │           ├── cmsis_armclang_ltm.h
│   │   │   │   │           ├── cmsis_compiler.h
│   │   │   │   │           ├── cmsis_gcc.h
│   │   │   │   │           ├── cmsis_iccarm.h
│   │   │   │   │           ├── cmsis_tiarmclang.h
│   │   │   │   │           ├── cmsis_version.h
│   │   │   │   │           ├── core_armv81mml.h
│   │   │   │   │           ├── core_armv8mbl.h
│   │   │   │   │           ├── core_armv8mml.h
│   │   │   │   │           ├── core_cm0.h
│   │   │   │   │           ├── core_cm0plus.h
│   │   │   │   │           ├── core_cm1.h
│   │   │   │   │           ├── core_cm23.h
│   │   │   │   │           ├── core_cm3.h
│   │   │   │   │           ├── core_cm33.h
│   │   │   │   │           ├── core_cm35p.h
│   │   │   │   │           ├── core_cm4.h
│   │   │   │   │           ├── core_cm55.h
│   │   │   │   │           ├── core_cm7.h
│   │   │   │   │           ├── core_cm85.h
│   │   │   │   │           ├── core_sc000.h
│   │   │   │   │           ├── core_sc300.h
│   │   │   │   │           ├── core_starmc1.h
│   │   │   │   │           ├── mpu_armv7.h
│   │   │   │   │           ├── mpu_armv8.h
│   │   │   │   │           ├── pac_armv81.h
│   │   │   │   │           ├── pmu_armv8.h
│   │   │   │   │           └── tz_context.h
│   │   │   │   ├── .gitattributes
│   │   │   │   ├── .gitignore
│   │   │   │   ├── ARM.CMSIS.pdsc
│   │   │   │   ├── CMSIS_Review_Meeting_2020.pdf
│   │   │   │   ├── Jenkinsfile
│   │   │   │   ├── LICENSE.txt
│   │   │   │   ├── linter.py
│   │   │   │   ├── README.md
│   │   │   │   └── Scalable Software Stack.pdf
│   │   │   └── device
│   │   │       ├── .github
│   │   │       │   ├── ISSUE_TEMPLATE.md
│   │   │       │   └── PULL_REQUEST_TEMPLATE.md
│   │   │       ├── Include
│   │   │       │   ├── stm32f401xc.h
│   │   │       │   ├── stm32f401xe.h
│   │   │       │   ├── stm32f405xx.h
│   │   │       │   ├── stm32f407xx.h
│   │   │       │   ├── stm32f410cx.h
│   │   │       │   ├── stm32f410rx.h
│   │   │       │   ├── stm32f410tx.h
│   │   │       │   ├── stm32f411xe.h
│   │   │       │   ├── stm32f412cx.h
│   │   │       │   ├── stm32f412rx.h
│   │   │       │   ├── stm32f412vx.h
│   │   │       │   ├── stm32f412zx.h
│   │   │       │   ├── stm32f413xx.h
│   │   │       │   ├── stm32f415xx.h
│   │   │       │   ├── stm32f417xx.h
│   │   │       │   ├── stm32f423xx.h
│   │   │       │   ├── stm32f427xx.h
│   │   │       │   ├── stm32f429xx.h
│   │   │       │   ├── stm32f437xx.h
│   │   │       │   ├── stm32f439xx.h
│   │   │       │   ├── stm32f446xx.h
│   │   │       │   ├── stm32f469xx.h
│   │   │       │   ├── stm32f479xx.h
│   │   │       │   ├── stm32f4xx.h
│   │   │       │   └── system_stm32f4xx.h
│   │   │       ├── Source
│   │   │       │   └── Templates
│   │   │       │       ├── arm
│   │   │       │       │   ├── startup_stm32f401xc.s
│   │   │       │       │   ├── startup_stm32f401xe.s
│   │   │       │       │   ├── startup_stm32f405xx.s
│   │   │       │       │   ├── startup_stm32f407xx.s
│   │   │       │       │   ├── startup_stm32f410cx.s
│   │   │       │       │   ├── startup_stm32f410rx.s
│   │   │       │       │   ├── startup_stm32f410tx.s
│   │   │       │       │   ├── startup_stm32f411xe.s
│   │   │       │       │   ├── startup_stm32f412cx.s
│   │   │       │       │   ├── startup_stm32f412rx.s
│   │   │       │       │   ├── startup_stm32f412vx.s
│   │   │       │       │   ├── startup_stm32f412zx.s
│   │   │       │       │   ├── startup_stm32f413xx.s
│   │   │       │       │   ├── startup_stm32f415xx.s
│   │   │       │       │   ├── startup_stm32f417xx.s
│   │   │       │       │   ├── startup_stm32f423xx.s
│   │   │       │       │   ├── startup_stm32f427xx.s
│   │   │       │       │   ├── startup_stm32f429xx.s
│   │   │       │       │   ├── startup_stm32f437xx.s
│   │   │       │       │   ├── startup_stm32f439xx.s
│   │   │       │       │   ├── startup_stm32f446xx.s
│   │   │       │       │   ├── startup_stm32f469xx.s
│   │   │       │       │   └── startup_stm32f479xx.s
│   │   │       │       ├── gcc
│   │   │       │       │   ├── startup_stm32f401xc.s
│   │   │       │       │   ├── startup_stm32f401xe.s
│   │   │       │       │   ├── startup_stm32f405xx.s
│   │   │       │       │   ├── startup_stm32f407xx.s
│   │   │       │       │   ├── startup_stm32f410cx.s
│   │   │       │       │   ├── startup_stm32f410rx.s
│   │   │       │       │   ├── startup_stm32f410tx.s
│   │   │       │       │   ├── startup_stm32f411xe.s
│   │   │       │       │   ├── startup_stm32f412cx.s
│   │   │       │       │   ├── startup_stm32f412rx.s
│   │   │       │       │   ├── startup_stm32f412vx.s
│   │   │       │       │   ├── startup_stm32f412zx.s
│   │   │       │       │   ├── startup_stm32f413xx.s
│   │   │       │       │   ├── startup_stm32f415xx.s
│   │   │       │       │   ├── startup_stm32f417xx.s
│   │   │       │       │   ├── startup_stm32f423xx.s
│   │   │       │       │   ├── startup_stm32f427xx.s
│   │   │       │       │   ├── startup_stm32f429xx.s
│   │   │       │       │   ├── startup_stm32f437xx.s
│   │   │       │       │   ├── startup_stm32f439xx.s
│   │   │       │       │   ├── startup_stm32f446xx.s
│   │   │       │       │   ├── startup_stm32f469xx.s
│   │   │       │       │   └── startup_stm32f479xx.s
│   │   │       │       ├── iar
│   │   │       │       │   ├── linker
│   │   │       │       │   │   ├── stm32f401xc_flash.icf
│   │   │       │       │   │   ├── stm32f401xc_sram.icf
│   │   │       │       │   │   ├── stm32f401xe_flash.icf
│   │   │       │       │   │   ├── stm32f401xe_sram.icf
│   │   │       │       │   │   ├── stm32f405xx_flash.icf
│   │   │       │       │   │   ├── stm32f405xx_sram.icf
│   │   │       │       │   │   ├── stm32f407xx_flash.icf
│   │   │       │       │   │   ├── stm32f407xx_sram.icf
│   │   │       │       │   │   ├── stm32f410cx_flash.icf
│   │   │       │       │   │   ├── stm32f410cx_sram.icf
│   │   │       │       │   │   ├── stm32f410rx_flash.icf
│   │   │       │       │   │   ├── stm32f410rx_sram.icf
│   │   │       │       │   │   ├── stm32f410tx_flash.icf
│   │   │       │       │   │   ├── stm32f410tx_sram.icf
│   │   │       │       │   │   ├── stm32f411xe_flash.icf
│   │   │       │       │   │   ├── stm32f411xe_sram.icf
│   │   │       │       │   │   ├── stm32f412cx_flash.icf
│   │   │       │       │   │   ├── stm32f412cx_sram.icf
│   │   │       │       │   │   ├── stm32f412rx_flash.icf
│   │   │       │       │   │   ├── stm32f412rx_sram.icf
│   │   │       │       │   │   ├── stm32f412vx_flash.icf
│   │   │       │       │   │   ├── stm32f412vx_sram.icf
│   │   │       │       │   │   ├── stm32f412zx_flash.icf
│   │   │       │       │   │   ├── stm32f412zx_sram.icf
│   │   │       │       │   │   ├── stm32f413xx_flash.icf
│   │   │       │       │   │   ├── stm32f413xx_sram.icf
│   │   │       │       │   │   ├── stm32f415xx_flash.icf
│   │   │       │       │   │   ├── stm32f415xx_sram.icf
│   │   │       │       │   │   ├── stm32f417xx_flash.icf
│   │   │       │       │   │   ├── stm32f417xx_sram.icf
│   │   │       │       │   │   ├── stm32f423xx_flash.icf
│   │   │       │       │   │   ├── stm32f423xx_sram.icf
│   │   │       │       │   │   ├── stm32f427xx_flash.icf
│   │   │       │       │   │   ├── stm32f427xx_sram.icf
│   │   │       │       │   │   ├── stm32f429xx_flash.icf
│   │   │       │       │   │   ├── stm32f429xx_sram.icf
│   │   │       │       │   │   ├── stm32f437xx_flash.icf
│   │   │       │       │   │   ├── stm32f437xx_sram.icf
│   │   │       │       │   │   ├── stm32f439xx_flash.icf
│   │   │       │       │   │   ├── stm32f439xx_sram.icf
│   │   │       │       │   │   ├── stm32f446xx_flash.icf
│   │   │       │       │   │   ├── stm32f446xx_sram.icf
│   │   │       │       │   │   ├── stm32f469xx_flash.icf
│   │   │       │       │   │   ├── stm32f469xx_sram.icf
│   │   │       │       │   │   ├── stm32f479xx_flash.icf
│   │   │       │       │   │   └── stm32f479xx_sram.icf
│   │   │       │       │   ├── startup_stm32f401xc.s
│   │   │       │       │   ├── startup_stm32f401xe.s
│   │   │       │       │   ├── startup_stm32f405xx.s
│   │   │       │       │   ├── startup_stm32f407xx.s
│   │   │       │       │   ├── startup_stm32f410cx.s
│   │   │       │       │   ├── startup_stm32f410rx.s
│   │   │       │       │   ├── startup_stm32f410tx.s
│   │   │       │       │   ├── startup_stm32f411xe.s
│   │   │       │       │   ├── startup_stm32f412cx.s
│   │   │       │       │   ├── startup_stm32f412rx.s
│   │   │       │       │   ├── startup_stm32f412vx.s
│   │   │       │       │   ├── startup_stm32f412zx.s
│   │   │       │       │   ├── startup_stm32f413xx.s
│   │   │       │       │   ├── startup_stm32f415xx.s
│   │   │       │       │   ├── startup_stm32f417xx.s
│   │   │       │       │   ├── startup_stm32f423xx.s
│   │   │       │       │   ├── startup_stm32f427xx.s
│   │   │       │       │   ├── startup_stm32f429xx.s
│   │   │       │       │   ├── startup_stm32f437xx.s
│   │   │       │       │   ├── startup_stm32f439xx.s
│   │   │       │       │   ├── startup_stm32f446xx.s
│   │   │       │       │   ├── startup_stm32f469xx.s
│   │   │       │       │   └── startup_stm32f479xx.s
│   │   │       │       └── system_stm32f4xx.c
│   │   │       ├── _htmresc
│   │   │       │   ├── favicon.png
│   │   │       │   ├── mini-st_2020.css
│   │   │       │   └── st_logo_2020.png
│   │   │       ├── CODE_OF_CONDUCT.md
│   │   │       ├── CONTRIBUTING.md
│   │   │       ├── LICENSE.md
│   │   │       ├── README.md
│   │   │       ├── Release_Notes.html
│   │   │       └── SECURITY.md
│   │   └── stm32f4xx-hal-driver
│   │       ├── .github
│   │       │   ├── ISSUE_TEMPLATE.md
│   │       │   └── PULL_REQUEST_TEMPLATE.md
│   │       ├── Inc
│   │       │   ├── Legacy
│   │       │   │   ├── stm32f4xx_hal_can_legacy.h
│   │       │   │   ├── stm32f4xx_hal_eth_legacy.h
│   │       │   │   └── stm32_hal_legacy.h
│   │       │   ├── stm32f4xx_hal.h
│   │       │   ├── stm32f4xx_hal_adc.h
│   │       │   ├── stm32f4xx_hal_adc_ex.h
│   │       │   ├── stm32f4xx_hal_can.h
│   │       │   ├── stm32f4xx_hal_cec.h
│   │       │   ├── stm32f4xx_hal_conf_template.h
│   │       │   ├── stm32f4xx_hal_cortex.h
│   │       │   ├── stm32f4xx_hal_crc.h
│   │       │   ├── stm32f4xx_hal_cryp.h
│   │       │   ├── stm32f4xx_hal_cryp_ex.h
│   │       │   ├── stm32f4xx_hal_dac.h
│   │       │   ├── stm32f4xx_hal_dac_ex.h
│   │       │   ├── stm32f4xx_hal_dcmi.h
│   │       │   ├── stm32f4xx_hal_dcmi_ex.h
│   │       │   ├── stm32f4xx_hal_def.h
│   │       │   ├── stm32f4xx_hal_dfsdm.h
│   │       │   ├── stm32f4xx_hal_dma.h
│   │       │   ├── stm32f4xx_hal_dma2d.h
│   │       │   ├── stm32f4xx_hal_dma_ex.h
│   │       │   ├── stm32f4xx_hal_dsi.h
│   │       │   ├── stm32f4xx_hal_eth.h
│   │       │   ├── stm32f4xx_hal_exti.h
│   │       │   ├── stm32f4xx_hal_flash.h
│   │       │   ├── stm32f4xx_hal_flash_ex.h
│   │       │   ├── stm32f4xx_hal_flash_ramfunc.h
│   │       │   ├── stm32f4xx_hal_fmpi2c.h
│   │       │   ├── stm32f4xx_hal_fmpi2c_ex.h
│   │       │   ├── stm32f4xx_hal_fmpsmbus.h
│   │       │   ├── stm32f4xx_hal_fmpsmbus_ex.h
│   │       │   ├── stm32f4xx_hal_gpio.h
│   │       │   ├── stm32f4xx_hal_gpio_ex.h
│   │       │   ├── stm32f4xx_hal_hash.h
│   │       │   ├── stm32f4xx_hal_hash_ex.h
│   │       │   ├── stm32f4xx_hal_hcd.h
│   │       │   ├── stm32f4xx_hal_i2c.h
│   │       │   ├── stm32f4xx_hal_i2c_ex.h
│   │       │   ├── stm32f4xx_hal_i2s.h
│   │       │   ├── stm32f4xx_hal_i2s_ex.h
│   │       │   ├── stm32f4xx_hal_irda.h
│   │       │   ├── stm32f4xx_hal_iwdg.h
│   │       │   ├── stm32f4xx_hal_lptim.h
│   │       │   ├── stm32f4xx_hal_ltdc.h
│   │       │   ├── stm32f4xx_hal_ltdc_ex.h
│   │       │   ├── stm32f4xx_hal_mmc.h
│   │       │   ├── stm32f4xx_hal_nand.h
│   │       │   ├── stm32f4xx_hal_nor.h
│   │       │   ├── stm32f4xx_hal_pccard.h
│   │       │   ├── stm32f4xx_hal_pcd.h
│   │       │   ├── stm32f4xx_hal_pcd_ex.h
│   │       │   ├── stm32f4xx_hal_pwr.h
│   │       │   ├── stm32f4xx_hal_pwr_ex.h
│   │       │   ├── stm32f4xx_hal_qspi.h
│   │       │   ├── stm32f4xx_hal_rcc.h
│   │       │   ├── stm32f4xx_hal_rcc_ex.h
│   │       │   ├── stm32f4xx_hal_rng.h
│   │       │   ├── stm32f4xx_hal_rtc.h
│   │       │   ├── stm32f4xx_hal_rtc_ex.h
│   │       │   ├── stm32f4xx_hal_sai.h
│   │       │   ├── stm32f4xx_hal_sai_ex.h
│   │       │   ├── stm32f4xx_hal_sd.h
│   │       │   ├── stm32f4xx_hal_sdram.h
│   │       │   ├── stm32f4xx_hal_smartcard.h
│   │       │   ├── stm32f4xx_hal_smbus.h
│   │       │   ├── stm32f4xx_hal_spdifrx.h
│   │       │   ├── stm32f4xx_hal_spi.h
│   │       │   ├── stm32f4xx_hal_sram.h
│   │       │   ├── stm32f4xx_hal_tim.h
│   │       │   ├── stm32f4xx_hal_tim_ex.h
│   │       │   ├── stm32f4xx_hal_uart.h
│   │       │   ├── stm32f4xx_hal_usart.h
│   │       │   ├── stm32f4xx_hal_wwdg.h
│   │       │   ├── stm32f4xx_ll_adc.h
│   │       │   ├── stm32f4xx_ll_bus.h
│   │       │   ├── stm32f4xx_ll_cortex.h
│   │       │   ├── stm32f4xx_ll_crc.h
│   │       │   ├── stm32f4xx_ll_dac.h
│   │       │   ├── stm32f4xx_ll_dma.h
│   │       │   ├── stm32f4xx_ll_dma2d.h
│   │       │   ├── stm32f4xx_ll_exti.h
│   │       │   ├── stm32f4xx_ll_fmc.h
│   │       │   ├── stm32f4xx_ll_fmpi2c.h
│   │       │   ├── stm32f4xx_ll_fsmc.h
│   │       │   ├── stm32f4xx_ll_gpio.h
│   │       │   ├── stm32f4xx_ll_i2c.h
│   │       │   ├── stm32f4xx_ll_iwdg.h
│   │       │   ├── stm32f4xx_ll_lptim.h
│   │       │   ├── stm32f4xx_ll_pwr.h
│   │       │   ├── stm32f4xx_ll_rcc.h
│   │       │   ├── stm32f4xx_ll_rng.h
│   │       │   ├── stm32f4xx_ll_rtc.h
│   │       │   ├── stm32f4xx_ll_sdmmc.h
│   │       │   ├── stm32f4xx_ll_spi.h
│   │       │   ├── stm32f4xx_ll_system.h
│   │       │   ├── stm32f4xx_ll_tim.h
│   │       │   ├── stm32f4xx_ll_usart.h
│   │       │   ├── stm32f4xx_ll_usb.h
│   │       │   ├── stm32f4xx_ll_utils.h
│   │       │   ├── stm32f4xx_ll_wwdg.h
│   │       │   └── stm32_assert_template.h
│   │       ├── Src
│   │       │   ├── Legacy
│   │       │   │   ├── stm32f4xx_hal_can.c
│   │       │   │   └── stm32f4xx_hal_eth.c
│   │       │   ├── stm32f4xx_hal.c
│   │       │   ├── stm32f4xx_hal_adc.c
│   │       │   ├── stm32f4xx_hal_adc_ex.c
│   │       │   ├── stm32f4xx_hal_can.c
│   │       │   ├── stm32f4xx_hal_cec.c
│   │       │   ├── stm32f4xx_hal_cortex.c
│   │       │   ├── stm32f4xx_hal_crc.c
│   │       │   ├── stm32f4xx_hal_cryp.c
│   │       │   ├── stm32f4xx_hal_cryp_ex.c
│   │       │   ├── stm32f4xx_hal_dac.c
│   │       │   ├── stm32f4xx_hal_dac_ex.c
│   │       │   ├── stm32f4xx_hal_dcmi.c
│   │       │   ├── stm32f4xx_hal_dcmi_ex.c
│   │       │   ├── stm32f4xx_hal_dfsdm.c
│   │       │   ├── stm32f4xx_hal_dma.c
│   │       │   ├── stm32f4xx_hal_dma2d.c
│   │       │   ├── stm32f4xx_hal_dma_ex.c
│   │       │   ├── stm32f4xx_hal_dsi.c
│   │       │   ├── stm32f4xx_hal_eth.c
│   │       │   ├── stm32f4xx_hal_exti.c
│   │       │   ├── stm32f4xx_hal_flash.c
│   │       │   ├── stm32f4xx_hal_flash_ex.c
│   │       │   ├── stm32f4xx_hal_flash_ramfunc.c
│   │       │   ├── stm32f4xx_hal_fmpi2c.c
│   │       │   ├── stm32f4xx_hal_fmpi2c_ex.c
│   │       │   ├── stm32f4xx_hal_fmpsmbus.c
│   │       │   ├── stm32f4xx_hal_fmpsmbus_ex.c
│   │       │   ├── stm32f4xx_hal_gpio.c
│   │       │   ├── stm32f4xx_hal_hash.c
│   │       │   ├── stm32f4xx_hal_hash_ex.c
│   │       │   ├── stm32f4xx_hal_hcd.c
│   │       │   ├── stm32f4xx_hal_i2c.c
│   │       │   ├── stm32f4xx_hal_i2c_ex.c
│   │       │   ├── stm32f4xx_hal_i2s.c
│   │       │   ├── stm32f4xx_hal_i2s_ex.c
│   │       │   ├── stm32f4xx_hal_irda.c
│   │       │   ├── stm32f4xx_hal_iwdg.c
│   │       │   ├── stm32f4xx_hal_lptim.c
│   │       │   ├── stm32f4xx_hal_ltdc.c
│   │       │   ├── stm32f4xx_hal_ltdc_ex.c
│   │       │   ├── stm32f4xx_hal_mmc.c
│   │       │   ├── stm32f4xx_hal_msp_template.c
│   │       │   ├── stm32f4xx_hal_nand.c
│   │       │   ├── stm32f4xx_hal_nor.c
│   │       │   ├── stm32f4xx_hal_pccard.c
│   │       │   ├── stm32f4xx_hal_pcd.c
│   │       │   ├── stm32f4xx_hal_pcd_ex.c
│   │       │   ├── stm32f4xx_hal_pwr.c
│   │       │   ├── stm32f4xx_hal_pwr_ex.c
│   │       │   ├── stm32f4xx_hal_qspi.c
│   │       │   ├── stm32f4xx_hal_rcc.c
│   │       │   ├── stm32f4xx_hal_rcc_ex.c
│   │       │   ├── stm32f4xx_hal_rng.c
│   │       │   ├── stm32f4xx_hal_rtc.c
│   │       │   ├── stm32f4xx_hal_rtc_ex.c
│   │       │   ├── stm32f4xx_hal_sai.c
│   │       │   ├── stm32f4xx_hal_sai_ex.c
│   │       │   ├── stm32f4xx_hal_sd.c
│   │       │   ├── stm32f4xx_hal_sdram.c
│   │       │   ├── stm32f4xx_hal_smartcard.c
│   │       │   ├── stm32f4xx_hal_smbus.c
│   │       │   ├── stm32f4xx_hal_spdifrx.c
│   │       │   ├── stm32f4xx_hal_spi.c
│   │       │   ├── stm32f4xx_hal_sram.c
│   │       │   ├── stm32f4xx_hal_tim.c
│   │       │   ├── stm32f4xx_hal_timebase_rtc_alarm_template.c
│   │       │   ├── stm32f4xx_hal_timebase_rtc_wakeup_template.c
│   │       │   ├── stm32f4xx_hal_timebase_tim_template.c
│   │       │   ├── stm32f4xx_hal_tim_ex.c
│   │       │   ├── stm32f4xx_hal_uart.c
│   │       │   ├── stm32f4xx_hal_usart.c
│   │       │   ├── stm32f4xx_hal_wwdg.c
│   │       │   ├── stm32f4xx_ll_adc.c
│   │       │   ├── stm32f4xx_ll_crc.c
│   │       │   ├── stm32f4xx_ll_dac.c
│   │       │   ├── stm32f4xx_ll_dma.c
│   │       │   ├── stm32f4xx_ll_dma2d.c
│   │       │   ├── stm32f4xx_ll_exti.c
│   │       │   ├── stm32f4xx_ll_fmc.c
│   │       │   ├── stm32f4xx_ll_fmpi2c.c
│   │       │   ├── stm32f4xx_ll_fsmc.c
│   │       │   ├── stm32f4xx_ll_gpio.c
│   │       │   ├── stm32f4xx_ll_i2c.c
│   │       │   ├── stm32f4xx_ll_lptim.c
│   │       │   ├── stm32f4xx_ll_pwr.c
│   │       │   ├── stm32f4xx_ll_rcc.c
│   │       │   ├── stm32f4xx_ll_rng.c
│   │       │   ├── stm32f4xx_ll_rtc.c
│   │       │   ├── stm32f4xx_ll_sdmmc.c
│   │       │   ├── stm32f4xx_ll_spi.c
│   │       │   ├── stm32f4xx_ll_tim.c
│   │       │   ├── stm32f4xx_ll_usart.c
│   │       │   ├── stm32f4xx_ll_usb.c
│   │       │   └── stm32f4xx_ll_utils.c
│   │       ├── _htmresc
│   │       │   ├── favicon.png
│   │       │   ├── mini-st_2020.css
│   │       │   └── st_logo_2020.png
│   │       ├── CODE_OF_CONDUCT.md
│   │       ├── CONTRIBUTING.md
│   │       ├── LICENSE.md
│   │       ├── README.md
│   │       ├── Release_Notes.html
│   │       └── SECURITY.md
│   ├── tests
│   │   ├── unity
│   │   │   ├── src
│   │   │   │   ├── meson.build
│   │   │   │   ├── unity.c
│   │   │   │   ├── unity.h
│   │   │   │   └── unity_internals.h
│   │   │   ├── .editorconfig
│   │   │   ├── .gitattributes
│   │   │   ├── .gitignore
│   │   │   ├── CMakeLists.txt
│   │   │   ├── library.json
│   │   │   ├── LICENSE.txt
│   │   │   ├── meson.build
│   │   │   ├── meson_options.txt
│   │   │   ├── platformio-build.py
│   │   │   ├── README.md
│   │   │   └── unityConfig.cmake
│   │   ├── run_test_commands.txt
│   │   ├── test_bsp.c
│   │   ├── test_bsp.h
│   │   ├── test_runner.c
│   │   └── test_runner.h
│   └── STM32F407VGTX_FLASH.ld
├── templates
│   └── stm32f4_disc
│       ├── Projects
│       │   ├── STM32F4-Discovery
│       │   │   └── Templates_LL
│       │   │       ├── EWARM
│       │   │       │   ├── Project.ewd
│       │   │       │   ├── Project.ewp
│       │   │       │   ├── Project.eww
│       │   │       │   ├── startup_stm32f407xx.s
│       │   │       │   └── stm32f407xx_flash.icf
│       │   │       ├── Inc
│       │   │       │   ├── main.h
│       │   │       │   ├── stm32f4xx_it.h
│       │   │       │   └── stm32_assert.h
│       │   │       ├── MDK-ARM
│       │   │       │   ├── Project.uvoptx
│       │   │       │   ├── Project.uvprojx
│       │   │       │   └── startup_stm32f407xx.s
│       │   │       ├── Src
│       │   │       │   ├── main.c
│       │   │       │   ├── stm32f4xx_it.c
│       │   │       │   └── system_stm32f4xx.c
│       │   │       ├── STM32CubeIDE
│       │   │       │   ├── Example
│       │   │       │   │   ├── Startup
│       │   │       │   │   │   └── startup_stm32f407vgtx.s
│       │   │       │   │   └── User
│       │   │       │   │       ├── syscalls.c
│       │   │       │   │       └── sysmem.c
│       │   │       │   ├── .cproject
│       │   │       │   ├── .project
│       │   │       │   └── STM32F407VGTX_FLASH.ld
│       │   │       ├── LICENSE.md
│       │   │       └── readme.txt
│       │   ├── README.md
│       │   ├── Release_Notes.html
│       │   └── STM32CubeProjectsList.html
│       ├── .gitmodules
│       ├── CODE_OF_CONDUCT.md
│       ├── CONTRIBUTING.md
│       ├── LICENSE.md
│       ├── package.xml
│       ├── README.md
│       ├── Release_Notes.html
│       ├── sbom_cdx.json
│       └── SECURITY.md
├── tools
│   └── vscode
│       └── stm32f4_socrates.code-profile
├── .clang-format
├── .gitignore
├── .gitmodules
├── .python-version
├── LICENSE
├── Makefile
├── README.md
└── stm32f4_jenkins_ci.code-workspace
```
