static class RFController extends ItemBase
{
    static array<RFBox> RFBoxes = new array<RFBox>;

    void RFController()
    {
        GetGame().GetObjects("RFBox", RFBox, this);
        AddEvent("ItemCreated", "OnItemCreated");
    }
    void OnItemCreated(ItemBase item)
    {
        if (item is RFBox)
        {
            RFBoxes.Insert(RFBox);
        }
    }
    static array<RFBox> GetRFBoxes()
    {
        return RFBoxes;
    }
    void CheckRFBoxes()
    {
        foreach (RFBox box : RFBoxes)
        {
           if(box.GetFound())
           {
                RFBoxes.Remove(box);
           }
        }
    }
    void FoundRFBox(RFBox box)
    {
        foreach (RFBox box : RFBoxes)
        {
            if(box == box)
            {
                box.SetFound(true);
            }
        }
    }
}
class RFBox extends ItemBase
{
    bool found = false;
    void SetFound(bool found)
    {
        this.found = found;
    }
    bool GetFound()
    {
        return found;
    }

}