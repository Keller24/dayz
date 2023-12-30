class RFReceiverBase extends ItemBase
{  
    protected PlayerBase player;
    protected vector playerPos;
    protected ItemBase item;
    protected vector itemPos;
    protected float frequencies[9] = {121.31, 119.67, 231.55, 145.87, 187.33, 218.48, 219.78, 226.76, 252.41};
    protected string freqString;
    protected string freqDisplay;
    /*
    protected const string BEEP_SOUND = "RF Reciever\sounds\beep.ogg"; // Replace with your beep sound file path
    protected const string BEEP_SOUND_FAST = "RF Reciever\sounds\beep.ogg"; // Replace with your fast beep sound file path
    protected const string BEEP_SOUND_FASTEST = "RF Reciever\sounds\beep.ogg"; // Replace with your fastest beep sound file path
    protected const string TURNED_ON_SOUND = "RF Reciever\sounds\on.ogg"; // Replace with your turned on sound file path
    protected const string TURNED_OFF_SOUND = "RF Reciever\sounds\off.ogg"; // Replace with your turned off sound file path
    */
    protected const float DISTANCE_THRESHOLD = 150.0; // Replace with your desired distance threshold
    soundset BEEPS =
    {
        path = "RFReceiver\sounds"
    }
    GetGame.GetObjects("RFBox", RFBox, this);   
    GetGame.GetObjects("RFReceiver", RFReceiver, this);
    void RFReceiverBase()
    {
        if (GetGame().IsServer())
        { 
            player = GetHierarchyRootPlayer.Cast(PlayerBase);
            if (player)
            {
                playerPos = player.GetPosition();
                player.GetInventory();
                if (player.GetInventory().ItemAttached(RFReceiver) || player.GetInventory().GetItemInSlot("Hands") == RFReceiver)
                {
                    print("RF Receiver already in inventory");
                    IsTurnedOn();
                } 
            }
        }
    }
    void CheckPlayerDistance()
    {
        float boxDistance = 100000;
        foreach (RFBox box: RFController.GetRFBoxes())
        {
            if(vector.Distance(playerPos, box.GetPosition()) < boxDistance)
            {
                boxDistance = vector.Distance(playerPos, box.GetPosition());
                item = box;
                itemPos = item.GetPosition();
            }  
        }
        float distance = vector.Distance(playerPos, itemPos);
        if (distance <= DISTANCE_THRESHOLD && distance > 110)
        {    
            print("Distance is less than 150 and greater than 110");
           PlayBeepSound();
           DisplayFrequency();
        }
        else if (distance <= 110 && distance > 50)
        {
            print("Distance is less than 110 and greater than 50");
            PlayFastBeepSound();
            DisplayFrequency();
        }
        else if (distance <= 50 && distance >= 8)
        {
            PlayFastestBeepSound();
            DisplayFrequency();
        }
        else if(distance <= 7)
        {
            PlayFastestBeepSound();
            freqDisplay = "SIGNAL FOUND: " + freqString
        }

        else if(distance <= 0.5)
        {
            RFController.FoundRFBox(item);
            item = null;
        }
        else
        {
            StopBeepSound();
            DisplayFrequency();
        }
    }

    void PlayBeepSound()
    {
        
        print("Playing beep sound");
        SEffectManager.PlaySoundOnObject("BEEPS", this, 0, true);
    }
    void PlayFastBeepSound()
    {
        print("Playing fast beep sound");
        SEffectManager.PlaySoundOnObject("BEEPS", this, 0, true);
    }
    void PlayFastestBeepSound()
    {
        print("Playing fastest beep sound");
        SEffectManager.PlaySoundOnObject("BEEPS", this, 0, true);
    }

    override bool IsTurnedOn()
    {
        ItemBase RFReceiver = player.GetInventory().GetType(RFReceiver)
        if (RFReceiver)
        {
            if (RFReceiver.GetCompEM().IsSwitchedOn())
            {
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckPlayerDistance, delay, false);
                return true;
            }
        }
    }
    void StopBeepSound()
    {
        if(BEEPS)
        {
            print("Stopping beep sound");
            BEEPS.SoundStop();
        }
    }
    string DisplayFrequency()
    {          
        while (distance <= DISTANCE_THRESHOLD && distance >= 8)
        {   
                    
            foreach (float freq: frequencies)
            {
                if (freq.ToString() == freqString)
                {
                    while (distance <= DISTANCE_THRESHOLD && distance >= 8)
                    {   
                        freqDisplay = "SCANNING: " + freqString;
                    }
                }
                else
                {
                    freqDisplay = "NO SIGNAL";
                }
            }
        }
        return freqDisplay;
    }
    void PlayOnSound()
    {
       SEffectManager.PlaySoundLoop(TURNED_ON_SOUND, 10, true);
    }
    override void OnWorkStart()
    {
        super.OnWorkStart();
        CheckPlayerDistance();
        print("RF Receiver is turned on");
    }
    override void OnWork()
    {
        super.OnWork(float consumed_energy);
        CheckPlayerDistance();
        print("RF Receiver is working");
    }
    override void OnWorkStop()
    {
        super.OnWorkStop();
        StopBeepSound();
        print("RF Receiver is turned off");
    }
}