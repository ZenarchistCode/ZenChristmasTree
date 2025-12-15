modded class Hologram
{
    override float GetProjectionRadius() 
    {
        float projRadius = super.GetProjectionRadius();

        if (m_Parent && m_Parent.IsInherited(Zen_ChristmasTree_Green_Kit))
        {
            return projRadius * 0.2;
        }

        return projRadius;
    }

    override string ProjectionBasedOnParent()
    {
        if (m_Parent && m_Parent.IsInherited(Zen_ChristmasTree_Green_Kit))
        {
            Zen_ChristmasTree_Green_Kit treeKit = Zen_ChristmasTree_Green_Kit.Cast(m_Parent);
            if (treeKit)
                return "Zen_ChristmasTree_Green";
        }

        return super.ProjectionBasedOnParent();
    }

    override void UpdateHologram(float timeslice)
	{
        super.UpdateHologram(timeslice);

        Zen_ChristmasTree_Green_Kit zen_kit = Zen_ChristmasTree_Green_Kit.Cast(m_Parent);
        if (zen_kit)
        {
            vector pos = m_Projection.GetPosition();
            m_Projection.SetPosition(pos + "0 1.58 0");
        }
    }

    override EntityAI PlaceEntity(EntityAI entity_for_placing)
    {
        if (m_Parent && m_Parent.IsInherited(Zen_ChristmasTree_Green_Kit))
        {
            // Get kit
            Zen_ChristmasTree_Green_Kit treeKit = Zen_ChristmasTree_Green_Kit.Cast(m_Parent);

            // Create shelter on the ground in location of hologram
            Zen_ChristmasTree_Green tree = Zen_ChristmasTree_Green.Cast(GetGame().CreateObjectEx("Zen_ChristmasTree_Green", m_Projection.GetPosition(), ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS));

            // Validate object existence
            if (!tree)
                return entity_for_placing;

            // Set orientation
            tree.SetPosition(m_Projection.GetPosition());
            tree.SetOrientation(m_Projection.GetOrientation());
            tree.SetScale(0.2);
            tree.Update();

            return tree;
        }

        return super.PlaceEntity(entity_for_placing);
    }

    override void RefreshVisual()
	{
        super.RefreshVisual();

        if (m_Projection && m_Projection.IsInherited(Zen_ChristmasTree_Green))
        {
            m_Projection.SetScale(0.2);
            m_Projection.Update();
        }
	}
}