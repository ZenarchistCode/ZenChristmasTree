class Zen_ChristmasTree_Green_Static extends BuildingBase 
{
    XmasTreeLight m_TreeLight;

    void Zen_ChristmasTree_Green_Static()
	{
		CreateXmasLight();
	}

    void CreateXmasLight() 
    {
        if (!g_Game.IsDedicatedServer())
		{
			m_TreeLight = XmasTreeLight.Cast(ScriptedLightBase.CreateLight(XmasTreeLight, "0 0 0"));
			m_TreeLight.AttachOnMemoryPoint(this, "action");
		}
    }

    override void EEInit()
	{
        SetScale(0.28);
        Update();
	}
	
	override void EEDelete(EntityAI parent)
	{
		if (!g_Game.IsDedicatedServer())
		{
			if (m_TreeLight)
				m_TreeLight.Destroy();
		}
	}
}