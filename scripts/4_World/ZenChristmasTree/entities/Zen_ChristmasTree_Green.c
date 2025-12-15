class Zen_ChristmasTree_Green extends ItemBase 
{
    Object              m_ClutterCutter;
    XmasTreeLight 	    m_TreeLight;
	ref EffectSound 	m_AmbientSoundLoop;
	const string		LOOP_SOUND = "ChristmasMusic_SoundSet";
    
    bool m_ZenXmasMusicPlaying;

    void Zen_ChristmasTree_Green()
	{
		RegisterNetSyncVariableBool("m_ZenXmasMusicPlaying");
	}

    override void EEInit()
	{
        GrinchShrink();

        if (g_Game.IsDedicatedServer())
        {
            m_ClutterCutter = g_Game.CreateObjectEx("ClutterCutterFireplace", GetPosition(), ECE_PLACE_ON_SURFACE);
            m_ClutterCutter.SetOrientation(GetOrientation());
        }
	}

    override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

        if (g_Game.IsDedicatedServer())
        {
            if (m_ClutterCutter)
                g_Game.ObjectDelete(m_ClutterCutter);
        }
    }

    override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{
		super.OnItemLocationChanged(old_owner, new_owner);

        GrinchShrink();
	}

    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

        if (m_ZenXmasMusicPlaying)
        {
            StartZenXmasMusic();
        }
        else 
        {
            StopZenXmasMusic();
        }
    }

    override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionZenToggleChristmasMusic);

        // todo: dismantle action with hatchet/axe!
	}

    override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
        // SetScale does not work on items in hands - so putting this item in hands looks fucking massive lol
        // Funny but not very immersive seeing a giant tree run around. Hence the kit approach instead of making the tree itself deployable
		return false;
	}

	override bool IsTakeable()
	{
		return false;
	}

    void GrinchShrink()
    {
        SetScale(0.2);
        Update();
        SetAllowDamage(false);
    }

    bool IsZenXmasMusicPlaying() 
    {
        return m_ZenXmasMusicPlaying;
    }

    void StopZenXmasMusic()
    {
        if (g_Game.IsDedicatedServer())
        {
            m_ZenXmasMusicPlaying = false;
            SetSynchDirty();
        }
        else 
        {
            StopSoundSet(m_AmbientSoundLoop);
            if (m_TreeLight)
                m_TreeLight.FadeOut(3);
        }
    }

    void StartZenXmasMusic()
    {
        if (g_Game.IsDedicatedServer())
        {
            m_ZenXmasMusicPlaying = true;
            SetSynchDirty();
        }
        else 
        {
            if (!m_AmbientSoundLoop || !m_AmbientSoundLoop.IsPlaying())
            {
                PlaySoundSetLoop(m_AmbientSoundLoop, LOOP_SOUND, 0, 0);
                m_TreeLight = XmasTreeLight.Cast( ScriptedLightBase.CreateLight( XmasTreeLight, "0 0 0" ) );
			    m_TreeLight.AttachOnMemoryPoint( this, "action" );
            }
        }
    }
}