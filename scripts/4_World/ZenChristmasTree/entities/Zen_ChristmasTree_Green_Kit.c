class Zen_ChristmasTree_Green_Kit extends KitBase
{
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		if (g_Game.IsDedicatedServer())
		{
			StopItemSoundServer(SoundConstants.ITEM_DEPLOY_LOOP);
			g_Game.ObjectDelete(this);
		}
	}

    override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

        if (g_Game.IsClient())
        {
            GetItemSoundHandler().StopItemSoundClient(SoundConstants.ITEM_DEPLOY_LOOP);
        }
    }
}