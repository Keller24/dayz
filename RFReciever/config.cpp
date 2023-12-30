    
    class CfgMods
    {
        class RFReceiver
        {
            dir = "RFReceiver";
            picture = "";
            action = "";
            hideName = 1;
            hidePicture = 1;
            name = "RFReceiver";
            credits = "Keller";
            author = "Keller";
            authorID = "0";
            version = "1.0";
            extra = 0;
            type = "mod";
            dependencies[] = {"World"};
            class defs
            {
                class worldScriptModule
                {
                    value = "";
                    files[] = {"RFReceiver/addons/scripts/4_World"};
                };
            };
        };
    };
    class cfgPatches
    {
        class RFReceiver
        {
            units[] = {"RFReceiver", "RFBox"};
            weapons[] = {};
            requiredVersion = 0.1;
            requiredAddons[] = {"DZ_Data"};
        };
    };

    class CfgVehicles
    {
        class Container_Base;
        class Inventory_Base;
        class ItemGPS;
        class GPSReceiver;
        class RFReceiver : GPSReceiver
        {
            scope = 2;
            displayName = "RF Receiver";
            descriptionShort = "One way radio receiver, commonly used by stalkers for finding stashes.";
            model = "\dz\gear\navigation\GPSReceiver.p3d";
            itemSize[] = { 1,2 };
            weight = 350;
            rotationFlags = 1;
            simulation = "ItemGPS";
            inventorySlot[] =
            {
                "WalkieTalkie"
            };
            attachments[] =
            {
                "BatteryD"
            };
            repairableWithKits[] = { 7 };
            repairCosts[] = { 50 };
            class EnergyManager
            {
                hasIcon = 1;
                autoSwitchOffWhenInCargo = 1;
                energyUsagePerSecond = 0.0099999998;
                plugType = 1;
                attachmentAction = 1;
                updateInterval = 3;
            };
            hiddenSelections[] =
            {
                "grid_1_0",
                "grid_1_1",
                "grid_1_2",
                "grid_2_0",
                "grid_2_1",
                "grid_2_2",
                "alt_0",
                "alt_1",
                "alt_2",
                "alt_3"
            };
        };
        class WaterproofBag_ColorBase;
        class WaterproofBag_Green : WaterproofBag_ColorBase
        {
            scope = 2;
            color = "Green";
            hiddenSelectionsTextures[] =
            {
                "\dz\gear\containers\Data\WaterproofBag_green_co.paa"
            };
        };

        class RFBox: WaterproofBag_Green
        {
    
		    scope=2;
		    color="Green";
		    hiddenSelectionsTextures[]=
		    {
			    "\dz\gear\containers\Data\WaterproofBag_green_co.paa"
		    };
	 
        };
    };
   
    class CfgSounds
    {
        class BEEPS
        {
            class BEEP_SOUND
            {
                name="BEEP_SOUND";
                sound[]=
                {
                    "RFReceiver\sounds\beep.ogg",
                    1,
                    1
                };
                titles[]={};
                volume=1;
            };
            class BEEP_SOUND_FAST
            {
                name="BEEP_SOUND_FAST";
                sound[]=
                {
                    "RFReceiver\sounds\beep.ogg",
                    1,
                    1
                };
                titles[]={};
                volume=1;
            };
            class BEEP_SOUND_FASTEST
            {
                name="BEEP_SOUND_FASTEST";
                sound[]=
                {
                    "RFReceiver\sounds\beep.ogg",
                    1,
                    1
                };
                titles[]={};
                volume=1;
            };
            class TURNED_ON_SOUND
            {
                name="TURNED_ON_SOUND";
                sound[]=
                {
                    "RFReceiver\sounds\on.ogg",
                    1,
                    1
                };
                titles[]={};
                volume=1;
            };
            class TURNED_OFF_SOUND
            {
                name="TURNED_OFF_SOUND";
                sound[]=
                {
                    "RFReceiver\sounds\off.ogg",
                    1,
                    1
                };
                titles[]={};
                volume=1;
            };
        }
        
    };
    
    
    