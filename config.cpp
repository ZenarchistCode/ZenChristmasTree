/*
	(c) 2025 | ZenChristmasTree | Zenarchist
*/

class CfgPatches
{
	class ZenChristmasTree
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class ZenChristmasTree
	{
		author = "Zenarchist";
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenChristmasTree/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenChristmasTree/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenChristmasTree/Scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class Inventory_Base;
	
	// Vanilla tree has sound effects, this doesn't
	class Zen_ChristmasTree_Green_Static: HouseNoDestruct
	{
		scope = 1;
		model="DZ\plants\tree\t_PiceaAbies_2s_green_xmas.p3d";
		soundImpactType="wood";
	};

	class Zen_ChristmasTree_Green_Kit: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_ZenChristmasTreeKit0";
		descriptionShort="$STR_CfgVehicles_ZenChristmasTreeKit1";
		model="\DZ\gear\camping\territory_flag_kit.p3d";
		rotationFlags=17;
		itemSize[]={1,5};
		weight=280;
		itemBehaviour=1;
		debug_ItemCategory=10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class AnimSourceHidden
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Inventory: AnimSourceHidden
			{
			};
			class Placing: AnimSourceHidden
			{
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet="FenceKit_crafting_1_SoundSet";
					id=1111;
				};
				class crafting_2
				{
					soundSet="FenceKit_crafting_2_SoundSet";
					id=1112;
				};
				class crafting_3
				{
					soundSet="FenceKit_crafting_3_SoundSet";
					id=1113;
				};
				class crafting_4
				{
					soundSet="FenceKit_crafting_4_SoundSet";
					id=1114;
				};
				class crafting_5
				{
					soundSet="FenceKit_crafting_5_SoundSet";
					id=1115;
				};
			};
		};
	};

	class Zen_ChristmasTree_Green: Inventory_Base 
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ZenChristmasTree0";
		descriptionShort = "$STR_CfgVehicles_ZenChristmasTree1";
		model="DZ\plants\tree\t_PiceaAbies_2s_green_xmas.p3d";
		weight = 5000;
		itemBehaviour=0;
		itemSize[]={10,10};
		soundImpactType="wood";
	};
};