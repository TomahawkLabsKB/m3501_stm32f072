I am TomahawkLabs and I have designed a drop in replacement PCB for the Apple M3501 using a custom [STM32 chip by nearestexit](https://github.com/nearestexit/kb_f072). The goal for this project was to create a drop in solution that keeps all the asthetics and core functionality of the M3501, but with native USB support. All LEDs function as they should and the custom cable works in both the left and right ADB ports. This project uses QMK to flash the keyboard.
-----------------------------------------------------
Equipment Required:

	1. Apple M3501 keyboard
	2. Apple ADB Cable
	3. Parts Kit
		a. A USB connector kit for creating the ADB passthrough USB cable
		b. A package of Diodes
		c. A Passives component kit with: LEDs, Resistors, Fuse, wires and connectors
		d. The MCU and header pins will be shipped in an ESD bag
		
Tools you will need:

	1. Soldering iron
	2. Solder
	3. Solder Sucker
	4. Flux
	5. Keycap Removal Tool
	6. Tweezers

Tools you may want for cleaning:

	1. Q-tip
	2. Isopropyl Alcohol 
	3. Vacuum
	4. Dish soap

Things to note:

    1. There are two unpopulated parts (S106 and S107). These were offboard buttons for Reset and Bootsel, but because Bootsel is wired incorrectly, to ground the parts have been omitted.
    2. D+ and D- may be labeled backwards, feedback welcome.
-----------------------------------------------------
PCB Assembly Instructions:

	1. Install Diodes orientated as the board indicates
	2. Install the fuse and resistors
	3. Install MCU
		a. Starting with the top side, Ensure proper, flush fitment of pins to both the PCB and MCU. You may need to sand down the plastic insulation of the header pins where they were cut for a proper fitment. 
		b. Once the MCU and PCB are flush with the insulation, tack in the 4 corners and any other pin on the long header pins. Doing this will lock in all 6 header pins flush to the MCU
		c. Flip the board, maintaining a flush fitment, and solder the underside to lock the MCU to the PCB
		d. Solder the remaining MCU pins on the top side
	4. Install LEDs
	5. Install USB breakout connectors, facing the connector release towards you
    6. Proceed to Daughterboard Wiring Instructions
-----------------------------------------------------
Daughterboard Wiring Instructions: 

	1. We will first need to desolder the wires connecting the two daughterboards to the original PCB. A bit of flux will help the solder flow to be removed. Be very careful when removing the wires. They are folded over onto the PCB and we will need to reuse both daughter boards for this project.
		a. My preferred method is to put flux on the solder joints, heat the joint with a soldering iron and use a solder pump to suck away the solder. Repeat this step for all the wires connected to the daughterboard.
	2. Cut the it included 5 conductor wiring harness to about ~35mm in wire length. Cutting it too short will cause fitment issues, cutting it too long is not an issue as there is plenty of room under the top case.
	3. Ensure your wiring harness colors match both on the connector side and the daughterboard side. You may need to re-pin the connector for it to match the pictures and directions.
	4. Solder the wires of the new wiring harness to the daughterboard 
		a. Yellow = Pin 5
		b. White  Pin 4
		c. Black = Pin 3
		d. Green = Pin 2
		e. Red = Pin 1
	5. Connect the Daughter boards into the replacement PCB, being aware the daughterboards are labeled R/H and L/H.
    6. Proceed to Cable Instructions
-----------------------------------------------------
Cable Instructions:

	1. Cut the ADB connector off the LONG side of the coiled cable. You will want the ADB connector on the SHORT side to connect to the keyboard and install the USB connecter on the LONG side.
	2. PUT THE USB CONNECTOR SHEATHING ON THE CABLE NOW.  Carefully slide the USB Connector Sheathing onto the wire cable relief end first, so you can slide it over the USB connector later. 
		a. The strain relief as been bored out to accommodate the thickness of the ADB cable and as such, is rather delicate. 
		b. Do not twist when pushing the sheathing on. Firmly push the connector from the plastic end over the wire. The wire relief will naturally be pushed back into the plastic part of the sheathing, which is not a problem.
		c. Be extra careful when pushing the sheathing over the USB connector as the strain relief will stick to ADB wire sheathing causing it to rip. Push the sheathing over the USB by pushing on the strain relief to ensure it does not get stuck on the ADB cable sheathing.
		d. Failure to do this step will lead to needing to redo the wiring, but cutting the cable shorter, to having to cut off the crimped connector and doing all if it over. Ask me how I know
	3. Remove ~30mm of the thick, grey shielding from the ADB cable
	4. Unwrap the braided shielding and foil shielding carefully, as they will be reused in the next step
	5. Wrap the foil around the base of the exposed wire near the thick, grey shielding ~10-12mm wide. You will make 2 - 3 layers of this wrap and then wrap the foil with the braided shielding to hold it in place and create a thick spot for the USB connector to crimp to. 
	6. Cut the exposed wires to ~12mm in length and strip off a small amount, being very careful as the wires are very thin and the shielding is brittle, making snaping the wires fairly easy
	7. The wires in ADB cables are NOT consistent in color and maybe pinout. We will need to use a multimeter to confirm wire paths.
	8. Connect the ADB connector to one of the daughterboard connected to the PCB and use a multimeter to confirm which cables are:
		a. 5v
		b. Ground
		c. D+
		d. D-
	9. Carefully remove the ADB cable before soldering the USB connector, if desired
	10. Solder the wires to the USB connector 
	11. Loosely plate USB connector in main USB connector housing to confirm proper USB connectivity. It should not immediately through an error when plugging in.
		a. Some systems may not see the device until put into bootsel. To do this, short BOOT to 3v3 on the MCU using a tweezers and press, then release the RST button installed on the MCU. Then un-short BOOT from 3v3.
		b. I have had 5v, Ground, and D+ and D- in the wrong spots without damage to the PCB or MCU, but be careful
	12. If all checks out, confirm the USB Connector Sheathing is install on the wire, there is no going back after this point.
	13. Ensure the USB connector area where we will be crimping fully is grabbing the sheathing wrap we made earlier and that the USB connector fully extends down housing for a proper fitment.
		a. You may need to trim a few millimeters off the thick, grey sheathing for everything to fit.
	14. Crimp the USB connector and double check again that there are no issues when connecting via USB
	15. Be extra careful when pushing the sheathing over the USB connector as the strain relief will stick to ADB wire sheathing causing it to rip. Push the sheathing over the USB by pushing on the strain relief to ensure it does not get stuck on the ADB cable sheathing.
    16. Proceed to Flashing Instructions
-----------------------------------------------------
Flashing Instructions:

	1. Ensure QMK MSYS and QMK toolbox are installed on your machine, I will be using windows file paths for these instructions.
	2. Copy folder "m3501_stm32f072" to C:\Users\%user%\qmk_firmware\keyboards
	3. Open QMK MSYS as admin
	4. Type "QMK setup" and run
	5. Type "QMK config" and run 
	6. Type "qmk compile -kb m3501_stm32f072 -km default"
	7. A bin file will be saved in the qmk_firmware folder C:\Users\%user%\qmk_firmware and should be titled "m3501_stm32f072_default.bin".
	8. Open QMK Toolbox as admin
	9. Connect the ADB to USB passthrough cable to your board
	10. On the MCU, short the pins 3v3 and BOOT, which are located directly next to each other on the bottom right of the MCU. A tweezers works great for this.
	11. When shorting BOOT to 3v3, press the RST button mounted on the MCU, release the button, then unshort Boot from 3v3
	12. If done correctly, the Scroll Lock LED with faintly glow. Your device should show up in QMK Toolbox.
	13. Click Open and locate the bin file we saved in Step 4 and click Flash
	14. Now your device should be read as a keyboard by your system. Test the functionality of each switch by shorting each switch location on the PCB with a tweezers.
		a. The locking switch used in Capslock works uniquely in that when shorted, the lock LED will light up, but immediately stop glowing when unshorted. Scroll and Num Lock use standard switches and their LEDS will toggle as you would expect when shorted.
    15. Once the keyboard PCB is confirmed to work we can remove the ADB to USB Passthrough cable from the daughterboard and proceed to PCB Removal Instructions
-----------------------------------------------------
PCB Removal Instructions

	1. Begin teardown of the keyboard as per this Ifixit guide and pause after step 4
		https://www.ifixit.com/Teardown/Apple+Extended+Keyboard+II+Teardown/42138
	2. Now that the top case housing has been removed, we will use the keycap removal tool to remove all of the keycaps from the keyboard. This is a great time to clean the keycaps.
		a. Soak the keycaps in warm soapy water for 30 minutes and wipe away dirt/grime with a clean rag.
	3. Continue the teardown and stop after Step 6, as we are only looking to remove the keyboard plate/PCB assembly. 
		a. This is a good opportunity to clean out the dirt/debris that can accumulate in the case with a vacuum to get the bulk and a Q-tip dipped in ISO to clean any tougher grime. 
	4. The PCB is connected to the plate via two screws, remove these two screws now, we will not be reusing them on the replacement PCB.
	5. Now, we can remove the PCB from the plate/PCB assembly by desoldering the switches.
		a. I highly suggest using a solder sucker to remove the solder from each leg of the switch
    6. Once the PCB has been removed , we can proceed to Finishing Up
-----------------------------------------------------
Finishing Up

	1. We will now solder the PCB to the switches in the plate assembly.
		a. Ensure all pins are straight as the PCB is a tight fit.  
		b. When soldering, start in a corner and press on the PCB when soldering to ensure a flush fitment of the PCB to the bottom housing of the switch.
		c. Repeat this step for several switches around the perimeter of the PCB to hold it in position
		d. Solder the remaining switches
	2. Test the keyboard functionality again. These switches are old and sometimes have issues. You may need to swap functional switches on a key you may not use into a more commonly used key that has a failed switch.
	3. Install the plate into the rubber feet at the bottom of the case and press down on the top of the plate to lock it into the retaining clips
	4. Install the daughterboards into the case
	5. Test cable fitment and connectivity on both the left and right side
-----------------------------------------------------
-----------------------------------------------------
