class CRF_3DMarker: SCR_InfoDisplayExtended
{
	[Attribute("{56B174A06C7ECFAB}UI/Layouts/HUD/CaptureAndHold/CaptureandHoldObjectiveLayout.layout", params: "layout")]
	protected ResourceName m_rObjectiveHUDLayout;
	
	//! Individual element wrappers
	protected ref array<ref SCR_CaptureAndHoldObjectiveDisplayObject> m_aMarkerElements = {};
	protected array<IEntity> m_aPlayers = {};
	
	//! Creates HUD elements for individual areas.
	override void DisplayStartDraw(IEntity owner)
	{
		UpdatePlayerMarkers(owner);
		CreateObjectiveDisplays(owner);
	}
	
	protected void CreateObjectiveDisplays(IEntity owner)
	{
		Widget objective;
		CRF_3DMarkerObject displayObject;
		for (int i = 0, count = m_aPlayers.Count(); i < count; i++)
		{
			marker = GetRootWidget().GetWorkspace().CreateWidgets(m_rObjectiveHUDLayout, GetRootWidget());
			if (!marker)
				continue;

			displayObject = new CRF_3DMarkerObject(marker, owner);
			m_aMarkerElements.Insert(displayObject);
		}
	}
	
	protected void UpdatePlayerMarkers(IEntity owner)
	{
		if (!m_aPlayers.Contains(owner))
			m_aPlayers.Insert(owner);
	}
}