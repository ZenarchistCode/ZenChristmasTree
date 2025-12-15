class ActionZenToggleChristmasMusic: ActionInteractBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		Zen_ChristmasTree_Green tree = Zen_ChristmasTree_Green.Cast(targetObject);

        if (!tree)
            return false;

        if (tree.IsZenXmasMusicPlaying())
        {
            m_Text = "#switch_off";
        }
        else 
        {
            m_Text = "#switch_on";
        }

		return true;
	}

	override void OnExecuteServer(ActionData action_data)
	{
        Object targetObject = action_data.m_Target.GetObject();
		Zen_ChristmasTree_Green tree = Zen_ChristmasTree_Green.Cast(targetObject);

        if (!tree)
            return;

        if (tree.IsZenXmasMusicPlaying())
            tree.StopZenXmasMusic();
        else 
            tree.StartZenXmasMusic();
	}
}