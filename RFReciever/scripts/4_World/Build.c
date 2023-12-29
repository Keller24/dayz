class RFReceiverBase extends ItemBase
{  
    protected PlayerBase player = GetGame().GetPlayer();
    protected vector playerPos = player.GetPosition();
    protected ItemBase item = ItemBase.Cast(RFBox);
    protected vector itemPos = item.GetPosition();
    protected float frequencies[9] = {121.31, 119.67, 231.55, 145.87, 187.33, 218.48, 219.78, 226.76, 252.41};
    protected string freqString = frequencies.GetRandomElement().ToString();
    protected string freqDisplay = "SCANNING: " + freqString;
    protected const string BEEP_SOUND = "RF Reciever\sounds\beep.ogg"; // Replace with your beep sound file path
    protected const string BEEP_SOUND_FAST = "RF Reciever\sounds\beep.ogg"; // Replace with your fast beep sound file path
    protected const string BEEP_SOUND_FASTEST = "RF Reciever\sounds\beep.ogg"; // Replace with your fastest beep sound file path
    protected const string TURNED_ON_SOUND = "RF Reciever\sounds\on.ogg"; // Replace with your turned on sound file path
    protected const string TURNED_OFF_SOUND = "RF Reciever\sounds\off.ogg"; // Replace with your turned off sound file path
    protected const float DISTANCE_THRESHOLD = 150.0; // Replace with your desired distance threshold

    void RFReceiverBase()
    {
        if (GetGame().IsServer())
        { 
            GetGame.GetObjects("RFBox", RFBox, this);
            GetGame.GetObjects("RFReceiver", RFReceiver, this);
            player.GetInventory();
            if (player.GetInventory().ItemAttached(RFReceiver) || player.GetInventory().GetItemInSlot("Hands") == RFReceiver)
            {
                print("RF Receiver already in inventory");
                if(IsTurnedOn())
                {
                    SetEventMask(EntityEvent.INIT);
                    CheckPlayerDistance();
                    print("RF Receiver is turned on");
                }
           } 
        }
    }
    void CheckPlayerDistance()
    {
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
        else
        {
            StopBeepSound();
            DisplayFrequency();
        }
    }

    void PlayBeepSound()
    {
        print("Playing beep sound");
        SEffectManager.PlaySoundOnObject()(BEEP_SOUND, 0, 0, true);
    }
    void PlayFastBeepSound()
    {
        print("Playing fast beep sound");
        SEffectManager.PlaySoundOnObject()(BEEP_SOUND, 0, 0, true);
    }
    void PlayFastestBeepSound()
    {
        print("Playing fastest beep sound");
        SEffectManager.PlaySoundOnObject()(BEEP_SOUND, 0, 0, true);
    }

    override bool IsTurnedOn()
    {
        ItemBase RFReceiver = player.GetInventory().GetType(RFReceiver)
        if (RFReceiver)
        {
            if (RFReceiver.GetCompEM().IsSwitchedOn())
            {
                return true;
            }
        }
    }
    void StopBeepSound()
    {
        if(BEEP_SOUND)
        {
            print("Stopping beep sound");
            BEE
            BEEP_SOUND.SoundStop();
        }
        else if(BEEP_SOUND_FAST)
        {
            print("Stopping fast beep sound");
            BEEP_SOUND_FAST.SoundStop();
        }
        else if(BEEP_SOUND_FASTEST)
        {
            print("Stopping fastest beep sound");
            BEEP_SOUND_FASTEST.SoundStop();
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
}