class CRF_3DMarkerObject
{
	//! Topmost widget of this object
	protected Widget m_wRoot;
	//! Text that displays objective distance
	protected TextWidget m_wDistanceText;
	//! Text that displays name or symbol of the objective
	protected TextWidget m_wNameText;

	//! The objective image
	protected ImageWidget m_wIcon;
	//! The objective is under attack symbol image
	protected ImageWidget m_wUnderAttackIcon;
	//! The major objective symbol image
	protected ImageWidget m_wMajorIcon;
	//! The backdrop image of this element
	protected ImageWidget m_wBackdropIcon;

	protected VerticalLayoutWidget m_wLayout;

	//! Blend progress of when within the area
	protected float m_fBlendScreenPosition;
	//! Color blending rate
	protected const float COLOR_BLEND_SPEED = 5.5;
	//! Position blending rate
	protected const float POSITION_BLEND_SPEED = 2.5;

	// Initial values
	protected float m_fOriginalXSize;
	protected float m_fOriginalYSize;
	protected float m_fOriginalTitleSize;
	protected float m_fOriginalTextSize;
	
	void CRF_3DMarkerObject(notnull Widget root, notnull IEntity player, notnull string text)
	{
		m_wRoot = root;
		m_AffiliatedArea = player;
		m_wNameText = TextWidget.Cast(m_wRoot.FindAnyWidget("Name"));
		m_fOriginalTitleSize = 15;

		m_wDistanceText = TextWidget.Cast(m_wRoot.FindAnyWidget("Distance"));
		m_wIcon = ImageWidget.Cast(m_wRoot.FindAnyWidget("Icon_Faction"));
		m_wBackdropIcon = ImageWidget.Cast(m_wRoot.FindAnyWidget("Icon_Backdrop"));

		m_wUnderAttackIcon = ImageWidget.Cast(m_wRoot.FindAnyWidget("Icon_UnderAttack"));
		m_wLayout = VerticalLayoutWidget.Cast(m_wRoot.FindAnyWidget("VerticalLayout"));
		m_fOriginalXSize = FrameSlot.GetSizeX(m_wLayout);
		m_fOriginalYSize = FrameSlot.GetSizeY(m_wLayout);

		m_wMajorIcon = ImageWidget.Cast(m_wRoot.FindAnyWidget("Icon_MajorMark"));

		m_fOriginalTextSize= 14;
	}
}