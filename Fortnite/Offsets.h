#pragma once
#include <Windows.h>

DWORD cs_gamerules_data = 0x0;
DWORD m_ArmorValue = 0x117CC;
DWORD m_Collision = 0x320;
DWORD m_CollisionGroup = 0x474;
DWORD m_Local = 0x2FCC;
DWORD m_MoveType = 0x25C;
DWORD m_OriginalOwnerXuidHigh = 0x31D4;
DWORD m_OriginalOwnerXuidLow = 0x31D0;
DWORD m_SurvivalGameRuleDecisionTypes = 0x1328;
DWORD m_SurvivalRules = 0xD00;
DWORD m_aimPunchAngle = 0x303C;
DWORD m_aimPunchAngleVel = 0x3048;
DWORD m_angEyeAnglesX = 0x117D0;
DWORD m_angEyeAnglesY = 0x117D4;
DWORD m_bBombDefused = 0x29C0;
DWORD m_bBombPlanted = 0x9A5;
DWORD m_bBombTicking = 0x2990;
DWORD m_bFreezePeriod = 0x20;
DWORD m_bGunGameImmunity = 0x9990;
DWORD m_bHasDefuser = 0x117DC;
DWORD m_bHasHelmet = 0x117C0;
DWORD m_bInReload = 0x32B5;
DWORD m_bIsDefusing = 0x997C;
DWORD m_bIsQueuedMatchmaking = 0x74;
DWORD m_bIsScoped = 0x9974;
DWORD m_bIsValveDS = 0x7C;
DWORD m_bSpotted = 0x93D;
DWORD m_bSpottedByMask = 0x980;
DWORD m_bStartedArming = 0x3400;
DWORD m_bUseCustomAutoExposureMax = 0x9D9;
DWORD m_bUseCustomAutoExposureMin = 0x9D8;
DWORD m_bUseCustomBloomScale = 0x9DA;
DWORD m_clrRender = 0x70;
DWORD m_dwBoneMatrix = 0x26A8;
DWORD m_fAccuracyPenalty = 0x3340;
DWORD m_fFlags = 0x104;
DWORD m_flC4Blow = 0x29A0;
DWORD m_flCustomAutoExposureMax = 0x9E0;
DWORD m_flCustomAutoExposureMin = 0x9DC;
DWORD m_flCustomBloomScale = 0x9E4;
DWORD m_flDefuseCountDown = 0x29BC;
DWORD m_flDefuseLength = 0x29B8;
DWORD m_flFallbackWear = 0x31E0;
DWORD m_flFlashDuration = 0x10470;
DWORD m_flFlashMaxAlpha = 0x1046C;
DWORD m_flLastBoneSetupTime = 0x2928;
DWORD m_flLowerBodyYawTarget = 0x9ADC;
DWORD m_flNextAttack = 0x2D80;
DWORD m_flNextPrimaryAttack = 0x3248;
DWORD m_flSimulationTime = 0x268;
DWORD m_flTimerLength = 0x29A4;
DWORD m_hActiveWeapon = 0x2F08;
DWORD m_hBombDefuser = 0x29C4;
DWORD m_hMyWeapons = 0x2E08;
DWORD m_hObserverTarget = 0x339C;
DWORD m_hOwner = 0x29DC;
DWORD m_hOwnerEntity = 0x14C;
DWORD m_hViewModel = 0x3308;
DWORD m_iAccountID = 0x2FD8;
DWORD m_iClip1 = 0x3274;
DWORD m_iCompetitiveRanking = 0x1A84;
DWORD m_iCompetitiveWins = 0x1B88;
DWORD m_iCrosshairId = 0x11838;
DWORD m_iDefaultFOV = 0x333C;
DWORD m_iEntityQuality = 0x2FBC;
DWORD m_iFOV = 0x31F4;
DWORD m_iFOVStart = 0x31F8;
DWORD m_iGlowIndex = 0x10488;
DWORD m_iHealth = 0x100;
DWORD m_iItemDefinitionIndex = 0x2FBA;
DWORD m_iItemIDHigh = 0x2FD0;
DWORD m_iMostRecentModelBoneCounter = 0x2690;
DWORD m_iObserverMode = 0x3388;
DWORD m_iShotsFired = 0x103E0;
DWORD m_iState = 0x3268;
DWORD m_iTeamNum = 0xF4;
DWORD m_lifeState = 0x25F;
DWORD m_nBombSite = 0x2994;
DWORD m_nFallbackPaintKit = 0x31D8;
DWORD m_nFallbackSeed = 0x31DC;
DWORD m_nFallbackStatTrak = 0x31E4;
DWORD m_nForceBone = 0x268C;
DWORD m_nTickBase = 0x3440;
DWORD m_nViewModelIndex = 0x29D0;
DWORD m_rgflCoordinateFrame = 0x444;
DWORD m_szCustomName = 0x304C;
DWORD m_szLastPlaceName = 0x35C4;
DWORD m_thirdPersonViewAngles = 0x31E8;
DWORD m_vecOrigin = 0x138;
DWORD m_vecVelocity = 0x114;
DWORD m_vecViewOffset = 0x108;
DWORD m_viewPunchAngle = 0x3030;
DWORD m_zoomLevel = 0x33E0;

DWORD anim_overlays = 0x2990;
DWORD clientstate_choked_commands = 0x4D30;
DWORD clientstate_delta_ticks = 0x174;
DWORD clientstate_last_outgoing_command = 0x4D2C;
DWORD clientstate_net_channel = 0x9C;
DWORD convar_name_hash_table = 0x2F0F8;
DWORD dwClientState = 0x58CFC4;
DWORD dwClientState_GetLocalPlayer = 0x180;
DWORD dwClientState_IsHLTV = 0x4D48;
DWORD dwClientState_Map = 0x28C;
DWORD dwClientState_MapDirectory = 0x188;
DWORD dwClientState_MaxPlayer = 0x388;
DWORD dwClientState_PlayerInfo = 0x52C0;
DWORD dwClientState_State = 0x108;
DWORD dwClientState_ViewAngles = 0x4D90;
DWORD dwEntityList = 0x4DD245C;
DWORD dwForceAttack = 0x3202970;
DWORD dwForceAttack2 = 0x320297C;
DWORD dwForceBackward = 0x320291C;
DWORD dwForceForward = 0x32029A0;
DWORD dwForceJump = 0x527C38C;
DWORD dwForceLeft = 0x3202928;
DWORD dwForceRight = 0x3202934;
DWORD dwGameDir = 0x62B880;
DWORD dwGameRulesProxy = 0x52EFBBC;
DWORD dwGetAllClasses = 0xDE0764;
DWORD dwGlobalVars = 0x58CCC8;
DWORD dwGlowObjectManager = 0x531B048;
DWORD dwInput = 0x5223A30;
DWORD dwInterfaceLinkList = 0x9692B4;
DWORD dwLocalPlayer = 0xDB65DC;
DWORD dwMouseEnable = 0xDBC2E8;
DWORD dwMouseEnablePtr = 0xDBC2B8;
DWORD dwPlayerResource = 0x3200CC0;
DWORD dwRadarBase = 0x52071D4;
DWORD dwSensitivity = 0xDBC184;
DWORD dwSensitivityPtr = 0xDBC158;
DWORD dwSetClanTag = 0x8A320;
DWORD dwViewMatrix = 0x4DC3D74;
DWORD dwWeaponTable = 0x52244F8;
DWORD dwWeaponTableIndex = 0x326C;
DWORD dwYawPtr = 0xDBBF48;
DWORD dwZoomSensitivityRatioPtr = 0xDC21B0;
DWORD dwbSendPackets = 0xD9572;
DWORD dwppDirect3DDevice9 = 0xA5050;
DWORD find_hud_element = 0x2E2650F0;
DWORD force_update_spectator_glow = 0x3BB80A;
DWORD interface_engine_cvar = 0x3E9EC;
DWORD is_c4_owner = 0x3C8890;
DWORD m_bDormant = 0xED;
DWORD m_flSpawnTime = 0x103C0;
DWORD m_pStudioHdr = 0x2950;
DWORD m_pitchClassPtr = 0x5207470;
DWORD m_yawClassPtr = 0xDBBF48;
DWORD model_ambient_min = 0x59003C;
DWORD set_abs_angles = 0x1E5430;
DWORD set_abs_origin = 0x1E5270;