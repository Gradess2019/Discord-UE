#pragma once
#include "CoreMinimal.h"
#include "DiscordEnums.generated.h"

/**
 * @brief Result of discord action
 */
UENUM(BlueprintType)
enum class EDiscordActionResult : uint8
{
	Ok = 0,
	ServiceUnavailable = 1,
	InvalidVersion = 2,
	LockFailed = 3,
	InternalError = 4,
	InvalidPayload = 5,
	InvalidCommand = 6,
	InvalidPermissions = 7,
	NotFetched = 8,
	NotFound = 9,
	Conflict = 10,
	InvalidSecret = 11,
	InvalidJoinSecret = 12,
	NoEligibleActivity = 13,
	InvalidInvite = 14,
	NotAuthenticated = 15,
	InvalidAccessToken = 16,
	ApplicationMismatch = 17,
	InvalidDataUrl = 18,
	InvalidBase64 = 19,
	NotFiltered = 20,
	LobbyFull = 21,
	InvalidLobbySecret = 22,
	InvalidFilename = 23,
	InvalidFileSize = 24,
	InvalidEntitlement = 25,
	NotInstalled = 26,
	NotRunning = 27,
	InsufficientBuffer = 28,
	PurchaseCanceled = 29,
	InvalidGuild = 30,
	InvalidEvent = 31,
	InvalidChannel = 32,
	InvalidOrigin = 33,
	RateLimited = 34,
	OAuth2Error = 35,
	SelectChannelTimeout = 36,
	GetGuildTimeout = 37,
	SelectVoiceForceRequired = 38,
	CaptureShortcutAlreadyListening = 39,
	UnauthorizedForAchievement = 40,
	InvalidGiftCode = 41,
	PurchaseError = 42,
	TransactionAborted = 43,
};

/**
 * @brief Activity type, like playing, streaming, etc.
 */
UENUM(BlueprintType)
enum EDiscordActivityType
{
	DiscordActivityType_Playing UMETA(DisplayName = "Playing"),
	DiscordActivityType_Streaming UMETA(DisplayName = "Streaming"),
	DiscordActivityType_Listening UMETA(DisplayName = "Listening"),
	DiscordActivityType_Watching UMETA(DisplayName = "Watching"),
};

/**
 * @brief Activity action type, like join or spectate
 */
UENUM(BlueprintType)
enum EDiscordActivityActionType {
	DiscordActivityActionType_None UMETA(DisplayName = "None"),
	DiscordActivityActionType_Join UMETA(DisplayName = "Join"),
	DiscordActivityActionType_Spectate UMETA(DisplayName = "Spectate"),
};

/**
 * @brief Activity join request reply, like yes, no or ignore
 */
UENUM(BlueprintType)
enum EDiscordActivityJoinRequestReply {
	DiscordActivityJoinRequestReply_No UMETA(DisplayName="No"),
	DiscordActivityJoinRequestReply_Yes UMETA(DisplayName="Yes"),
	DiscordActivityJoinRequestReply_Ignore UMETA(DisplayName="Ignore"),
};