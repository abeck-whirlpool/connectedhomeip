#include <app-common/zap-generated/attributes/Accessors.h>
#include <app-common/zap-generated/callback.h>
#include <app/data-model/Nullable.h>
#include <app/util/config.h>
#include <lib/core/DataModelTypes.h>
#ifdef MATTER_DM_PLUGIN_AIR_QUALITY_SERVER
#include "chef-air-quality.h"
#endif // MATTER_DM_PLUGIN_AIR_QUALITY_SERVER
#if defined(MATTER_DM_PLUGIN_CARBON_MONOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                  \
    defined(MATTER_DM_PLUGIN_CARBON_DIOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                   \
    defined(MATTER_DM_PLUGIN_NITROGEN_DIOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                 \
    defined(MATTER_DM_PLUGIN_OZONE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                            \
    defined(MATTER_DM_PLUGIN_PM2__5_CONCENTRATION_MEASUREMENT_SERVER) ||                                                           \
    defined(MATTER_DM_PLUGIN_FORMALDEHYDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                     \
    defined(MATTER_DM_PLUGIN_PM1_CONCENTRATION_MEASUREMENT_SERVER) ||                                                              \
    defined(MATTER_DM_PLUGIN_PM10_CONCENTRATION_MEASUREMENT_SERVER) ||                                                             \
    defined(MATTER_DM_PLUGIN_TOTAL_VOLATILE_ORGANIC_COMPOUNDS_CONCENTRATION_MEASUREMENT_SERVER) ||                                 \
    defined(MATTER_DM_PLUGIN_RADON_CONCENTRATION_MEASUREMENT_SERVER)
#include "chef-concentration-measurement.h"
#endif

using chip::app::DataModel::Nullable;

using namespace chip;
using namespace chip::app;
using namespace chip::app::Clusters;

Protocols::InteractionModel::Status emberAfExternalAttributeReadCallback(EndpointId endpoint, ClusterId clusterId,
                                                                         const EmberAfAttributeMetadata * attributeMetadata,
                                                                         uint8_t * buffer, uint16_t maxReadLength)
{
    switch (clusterId)
    {
#ifdef MATTER_DM_PLUGIN_AIR_QUALITY_SERVER
    case chip::app::Clusters::AirQuality::Id:
        return chefAirQualityReadCallback(endpoint, clusterId, attributeMetadata, buffer, maxReadLength);
#endif
#if defined(MATTER_DM_PLUGIN_CARBON_MONOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                  \
    defined(MATTER_DM_PLUGIN_CARBON_DIOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                   \
    defined(MATTER_DM_PLUGIN_NITROGEN_DIOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                 \
    defined(MATTER_DM_PLUGIN_OZONE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                            \
    defined(MATTER_DM_PLUGIN_PM2__5_CONCENTRATION_MEASUREMENT_SERVER) ||                                                           \
    defined(MATTER_DM_PLUGIN_FORMALDEHYDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                     \
    defined(MATTER_DM_PLUGIN_PM1_CONCENTRATION_MEASUREMENT_SERVER) ||                                                              \
    defined(MATTER_DM_PLUGIN_PM10_CONCENTRATION_MEASUREMENT_SERVER) ||                                                             \
    defined(MATTER_DM_PLUGIN_TOTAL_VOLATILE_ORGANIC_COMPOUNDS_CONCENTRATION_MEASUREMENT_SERVER) ||                                 \
    defined(MATTER_DM_PLUGIN_RADON_CONCENTRATION_MEASUREMENT_SERVER)
    case chip::app::Clusters::CarbonMonoxideConcentrationMeasurement::Id:
    case chip::app::Clusters::CarbonDioxideConcentrationMeasurement::Id:
    case chip::app::Clusters::NitrogenDioxideConcentrationMeasurement::Id:
    case chip::app::Clusters::OzoneConcentrationMeasurement::Id:
    case chip::app::Clusters::FormaldehydeConcentrationMeasurement::Id:
    case chip::app::Clusters::Pm1ConcentrationMeasurement::Id:
    case chip::app::Clusters::Pm25ConcentrationMeasurement::Id:
    case chip::app::Clusters::Pm10ConcentrationMeasurement::Id:
    case chip::app::Clusters::RadonConcentrationMeasurement::Id:
    case chip::app::Clusters::TotalVolatileOrganicCompoundsConcentrationMeasurement::Id:
        return chefConcentrationMeasurementReadCallback(endpoint, clusterId, attributeMetadata, buffer, maxReadLength);
#endif
    default:
        break;
    }
    return Protocols::InteractionModel::Status::Success;
}

/*
 *
Thread 3 "rootnode_airqua" hit Breakpoint 1, emberAfExternalAttributeWriteCallback (endpoint=1, clusterId=91,
    attributeMetadata=0x555555791f30 <(anonymous namespace)::generatedAttributes+1904>, buffer=0x7ffff68464ac "\001")
    at /home/erwinpan/matter/erwinpan1/master_1124_airqualitysensor/examples/chef/common/stubs.cpp:22
(gdb) p *attributeMetadata
$1 = {defaultValue = {ptrToDefaultValue = 0x0, defaultValue = 0, ptrToMinMaxValue = 0x0}, attributeId = 0, size = 1, attributeType =
48 '0', mask = 16 '\020'} (gdb)
*/

Protocols::InteractionModel::Status emberAfExternalAttributeWriteCallback(EndpointId endpoint, ClusterId clusterId,
                                                                          const EmberAfAttributeMetadata * attributeMetadata,
                                                                          uint8_t * buffer)
{
    switch (clusterId)
    {
#ifdef MATTER_DM_PLUGIN_AIR_QUALITY_SERVER
    case chip::app::Clusters::AirQuality::Id:
        return chefAirQualityWriteCallback(endpoint, clusterId, attributeMetadata, buffer);
#endif
#if defined(MATTER_DM_PLUGIN_CARBON_MONOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                  \
    defined(MATTER_DM_PLUGIN_CARBON_DIOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                   \
    defined(MATTER_DM_PLUGIN_NITROGEN_DIOXIDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                 \
    defined(MATTER_DM_PLUGIN_OZONE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                            \
    defined(MATTER_DM_PLUGIN_PM2__5_CONCENTRATION_MEASUREMENT_SERVER) ||                                                           \
    defined(MATTER_DM_PLUGIN_FORMALDEHYDE_CONCENTRATION_MEASUREMENT_SERVER) ||                                                     \
    defined(MATTER_DM_PLUGIN_PM1_CONCENTRATION_MEASUREMENT_SERVER) ||                                                              \
    defined(MATTER_DM_PLUGIN_PM10_CONCENTRATION_MEASUREMENT_SERVER) ||                                                             \
    defined(MATTER_DM_PLUGIN_TOTAL_VOLATILE_ORGANIC_COMPOUNDS_CONCENTRATION_MEASUREMENT_SERVER) ||                                 \
    defined(MATTER_DM_PLUGIN_RADON_CONCENTRATION_MEASUREMENT_SERVER)
    case chip::app::Clusters::CarbonMonoxideConcentrationMeasurement::Id:
    case chip::app::Clusters::CarbonDioxideConcentrationMeasurement::Id:
    case chip::app::Clusters::NitrogenDioxideConcentrationMeasurement::Id:
    case chip::app::Clusters::OzoneConcentrationMeasurement::Id:
    case chip::app::Clusters::FormaldehydeConcentrationMeasurement::Id:
    case chip::app::Clusters::Pm1ConcentrationMeasurement::Id:
    case chip::app::Clusters::Pm25ConcentrationMeasurement::Id:
    case chip::app::Clusters::Pm10ConcentrationMeasurement::Id:
    case chip::app::Clusters::RadonConcentrationMeasurement::Id:
    case chip::app::Clusters::TotalVolatileOrganicCompoundsConcentrationMeasurement::Id:
        return chefConcentrationMeasurementWriteCallback(endpoint, clusterId, attributeMetadata, buffer);
#endif
    default:
        break;
    }
    return Protocols::InteractionModel::Status::Success;
}

// Include door lock callbacks only when the server is enabled
#ifdef MATTER_DM_PLUGIN_DOOR_LOCK_SERVER
#include <app/clusters/door-lock-server/door-lock-server.h>

class LockManager
{
public:
    static constexpr uint32_t kNumEndpoints              = 1;
    static constexpr uint32_t kNumUsersPerEndpoint       = 2;
    static constexpr uint32_t kNumCredentialsPerEndpoint = 20;
    static constexpr uint32_t kNumCredentialsPerUser     = 10;
    static constexpr uint32_t kMaxNameLength             = 32;
    static constexpr uint32_t kMaxDataLength             = 16;

    struct Credential
    {
        bool set(DlCredentialStatus status, CredentialTypeEnum type, chip::ByteSpan newData)
        {
            if (newData.size() > kMaxDataLength || type != CredentialTypeEnum::kPin)
                return false;
            memcpy(data, newData.data(), newData.size());
            info = EmberAfPluginDoorLockCredentialInfo{
                status,
                type,
                chip::ByteSpan(data, newData.size()),
            };
            return true;
        }

        EmberAfPluginDoorLockCredentialInfo info = { DlCredentialStatus::kAvailable };
        uint8_t data[kMaxDataLength];
    };

    struct User
    {
        void set(chip::CharSpan newName, uint32_t userId, UserStatusEnum userStatus, UserTypeEnum type,
                 CredentialRuleEnum credentialRule)
        {
            size_t sz = std::min(sizeof(name), newName.size());
            memcpy(name, newName.data(), sz);
            info = EmberAfPluginDoorLockUserInfo{
                chip::CharSpan(name, sz), chip::Span<const CredentialStruct>(), userId, userStatus, type, credentialRule,
            };
        }
        bool addCredential(CredentialTypeEnum type, uint16_t index)
        {
            if (info.credentials.size() == kNumCredentialsPerUser)
                return false;
            auto & cr          = credentialMap[info.credentials.size()];
            cr.credentialType  = type;
            cr.credentialIndex = index;
            info.credentials   = chip::Span<const CredentialStruct>(credentialMap, info.credentials.size() + 1);
            return true;
        }

        EmberAfPluginDoorLockUserInfo info = { .userStatus = UserStatusEnum::kAvailable };
        char name[kMaxNameLength];
        CredentialStruct credentialMap[kNumCredentialsPerUser];
    };

    struct Endpoint
    {
        chip::EndpointId id;
        User users[kNumUsersPerEndpoint];
        Credential credentials[kNumCredentialsPerEndpoint];
    };

    static LockManager & Instance()
    {
        static LockManager instance;
        return instance;
    }

    LockManager() { defaultInitialize(); }

    bool getUser(chip::EndpointId endpointId, uint16_t userIndex, EmberAfPluginDoorLockUserInfo & user)
    {
        auto ep = findEndpoint(endpointId);
        if (!ep)
            return false;
        if (userIndex >= kNumUsersPerEndpoint)
            return false;
        user = ep->users[userIndex].info;
        return true;
    }

    bool setUser(chip::EndpointId endpointId, uint16_t userIndex, chip::FabricIndex creator, chip::FabricIndex modifier,
                 const chip::CharSpan & userName, uint32_t uniqueId, UserStatusEnum userStatus, UserTypeEnum usertype,
                 CredentialRuleEnum credentialRule, const CredentialStruct * credentials, size_t totalCredentials)
    {
        auto ep = findEndpoint(endpointId);
        if (!ep)
            return false;
        if (userIndex >= kNumUsersPerEndpoint || totalCredentials > kNumCredentialsPerUser)
            return false;
        ep->users[userIndex].set(userName, uniqueId, userStatus, usertype, credentialRule);
        ep->users[userIndex].info.creationSource     = DlAssetSource::kMatterIM;
        ep->users[userIndex].info.createdBy          = creator;
        ep->users[userIndex].info.modificationSource = DlAssetSource::kMatterIM;
        ep->users[userIndex].info.lastModifiedBy     = modifier;
        for (size_t i = 0; i < totalCredentials; i++)
            ep->users[userIndex].addCredential(credentials[i].credentialType, credentials[i].credentialIndex);
        return true;
    }

    bool getCredential(chip::EndpointId endpointId, uint16_t credentialIndex, CredentialTypeEnum credentialType,
                       EmberAfPluginDoorLockCredentialInfo & credential)
    {
        auto ep = findEndpoint(endpointId);
        if (!ep)
            return false;
        if (credentialIndex >= kNumCredentialsPerEndpoint)
            return false;
        if (credentialType != CredentialTypeEnum::kPin)
            return false;
        credential = ep->credentials[credentialIndex].info;
        return true;
    }

    bool setCredential(chip::EndpointId endpointId, uint16_t credentialIndex, chip::FabricIndex creator, chip::FabricIndex modifier,
                       DlCredentialStatus credentialStatus, CredentialTypeEnum credentialType,
                       const chip::ByteSpan & credentialData)
    {
        auto ep = findEndpoint(endpointId);
        if (!ep)
            return false;
        if (credentialIndex >= kNumCredentialsPerEndpoint)
            return false;
        if (credentialType != CredentialTypeEnum::kPin)
            return false;
        auto & credential = ep->credentials[credentialIndex];
        if (!credential.set(credentialStatus, credentialType, credentialData))
            return false;
        credential.info.creationSource     = DlAssetSource::kMatterIM;
        credential.info.createdBy          = creator;
        credential.info.modificationSource = DlAssetSource::kMatterIM;
        credential.info.lastModifiedBy     = modifier;
        return true;
    }

    bool checkPin(chip::EndpointId endpointId, const chip::Optional<chip::ByteSpan> & pinCode,
                  chip::app::Clusters::DoorLock::OperationErrorEnum & err)
    {
        if (!pinCode.HasValue())
        {
            err = OperationErrorEnum::kInvalidCredential;
            return false;
        }
        auto ep = findEndpoint(endpointId);
        if (!ep)
            return false;
        for (auto & pin : ep->credentials)
        {
            if (pin.info.status == DlCredentialStatus::kOccupied && pin.info.credentialData.data_equal(pinCode.Value()))
            {
                return true;
            }
        }
        err = OperationErrorEnum::kInvalidCredential;
        return false;
    }

private:
    Endpoint * findEndpoint(chip::EndpointId endpointId)
    {
        for (auto & e : endpoints)
        {
            if (e.id == endpointId)
                return &e;
        }
        return nullptr;
    }

    void defaultInitialize()
    {
        endpoints[0].id = 1;
        uint8_t pin[6]  = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36 };
        endpoints[0].credentials[0].set(DlCredentialStatus::kOccupied, CredentialTypeEnum::kPin, chip::ByteSpan(pin));
        endpoints[0].users[0].set("default"_span, 1, UserStatusEnum::kOccupiedEnabled, UserTypeEnum::kUnrestrictedUser,
                                  CredentialRuleEnum::kSingle);
        endpoints[0].users[0].addCredential(CredentialTypeEnum::kPin, 1);
    }

    Endpoint endpoints[kNumEndpoints];
};

bool emberAfPluginDoorLockOnDoorLockCommand(chip::EndpointId endpointId, const Nullable<chip::FabricIndex> & fabricIdx,
                                            const Nullable<chip::NodeId> & nodeId, const chip::Optional<chip::ByteSpan> & pinCode,
                                            chip::app::Clusters::DoorLock::OperationErrorEnum & err)
{
    err = OperationErrorEnum::kUnspecified;
    return DoorLockServer::Instance().SetLockState(endpointId, DlLockState::kLocked);
}

bool emberAfPluginDoorLockOnDoorUnlockCommand(chip::EndpointId endpointId, const Nullable<chip::FabricIndex> & fabricIdx,
                                              const Nullable<chip::NodeId> & nodeId, const chip::Optional<chip::ByteSpan> & pinCode,
                                              chip::app::Clusters::DoorLock::OperationErrorEnum & err)
{
    err = OperationErrorEnum::kUnspecified;
    return DoorLockServer::Instance().SetLockState(endpointId, DlLockState::kUnlocked);
}

bool emberAfPluginDoorLockGetUser(chip::EndpointId endpointId, uint16_t userIndex, EmberAfPluginDoorLockUserInfo & user)
{
    return LockManager::Instance().getUser(endpointId, userIndex - 1, user);
}

bool emberAfPluginDoorLockSetUser(chip::EndpointId endpointId, uint16_t userIndex, chip::FabricIndex creator,
                                  chip::FabricIndex modifier, const chip::CharSpan & userName, uint32_t uniqueId,
                                  UserStatusEnum userStatus, UserTypeEnum usertype, CredentialRuleEnum credentialRule,
                                  const CredentialStruct * credentials, size_t totalCredentials)
{
    return LockManager::Instance().setUser(endpointId, userIndex - 1, creator, modifier, userName, uniqueId, userStatus, usertype,
                                           credentialRule, credentials, totalCredentials);
}

bool emberAfPluginDoorLockGetCredential(chip::EndpointId endpointId, uint16_t credentialIndex, CredentialTypeEnum credentialType,
                                        EmberAfPluginDoorLockCredentialInfo & credential)
{
    return LockManager::Instance().getCredential(endpointId, credentialIndex - 1, credentialType, credential);
}

bool emberAfPluginDoorLockSetCredential(chip::EndpointId endpointId, uint16_t credentialIndex, chip::FabricIndex creator,
                                        chip::FabricIndex modifier, DlCredentialStatus credentialStatus,
                                        CredentialTypeEnum credentialType, const chip::ByteSpan & credentialData)
{
    return LockManager::Instance().setCredential(endpointId, credentialIndex - 1, creator, modifier, credentialStatus,
                                                 credentialType, credentialData);
}

#endif /* MATTER_DM_PLUGIN_DOOR_LOCK_SERVER */

void emberAfPluginSmokeCoAlarmSelfTestRequestCommand(EndpointId endpointId) {}

void MatterPostAttributeChangeCallback(const chip::app::ConcreteAttributePath & attributePath, uint8_t type, uint16_t size,
                                       uint8_t * value)
{
    ClusterId clusterId     = attributePath.mClusterId;
    AttributeId attributeId = attributePath.mAttributeId;
    ChipLogProgress(Zcl, "Cluster callback: " ChipLogFormatMEI, ChipLogValueMEI(clusterId));

    if (clusterId == OnOff::Id && attributeId == OnOff::Attributes::OnOff::Id)
    {
        ChipLogProgress(Zcl, "OnOff attribute ID: " ChipLogFormatMEI " Type: %u Value: %u, length %u", ChipLogValueMEI(attributeId),
                        type, *value, size);
    }
    else if (clusterId == LevelControl::Id)
    {
        ChipLogProgress(Zcl, "Level Control attribute ID: " ChipLogFormatMEI " Type: %u Value: %u, length %u",
                        ChipLogValueMEI(attributeId), type, *value, size);

        // WIP Apply attribute change to Light
    }
}

/** @brief OnOff Cluster Init
 *
 * This function is called when a specific cluster is initialized. It gives the
 * application an opportunity to take care of cluster initialization procedures.
 * It is called exactly once for each endpoint where cluster is present.
 *
 * TODO Issue #3841
 * emberAfOnOffClusterInitCallback happens before the stack initialize the cluster
 * attributes to the default value.
 * The logic here expects something similar to the deprecated Plugins callback
 * emberAfPluginOnOffClusterServerPostInitCallback.
 *
 */
void emberAfOnOffClusterInitCallback(EndpointId endpoint) {}

#ifdef MATTER_DM_PLUGIN_AUDIO_OUTPUT_SERVER
#include "audio-output/AudioOutputManager.h"
static AudioOutputManager audioOutputManager;

void emberAfAudioOutputClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: AudioOutput::SetDefaultDelegate");
    AudioOutput::SetDefaultDelegate(endpoint, &audioOutputManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_CHANNEL_SERVER
#include "channel/ChannelManager.h"
static ChannelManager channelManager;

void emberAfChannelClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: Channel::SetDefaultDelegate");
    Channel::SetDefaultDelegate(endpoint, &channelManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_KEYPAD_INPUT_SERVER
#include "keypad-input/KeypadInputManager.h"
static KeypadInputManager keypadInputManager;

void emberAfKeypadInputClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: KeypadInput::SetDefaultDelegate");
    KeypadInput::SetDefaultDelegate(endpoint, &keypadInputManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_LOW_POWER_SERVER
#include "low-power/LowPowerManager.h"
static LowPowerManager lowPowerManager;

void emberAfLowPowerClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: LowPower::SetDefaultDelegate");
    LowPower::SetDefaultDelegate(endpoint, &lowPowerManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_MEDIA_INPUT_SERVER
#include "media-input/MediaInputManager.h"
static MediaInputManager mediaInputManager;
void emberAfMediaInputClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: MediaInput::SetDefaultDelegate");
    MediaInput::SetDefaultDelegate(endpoint, &mediaInputManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_MEDIA_PLAYBACK_SERVER
#include "media-playback/MediaPlaybackManager.h"
static MediaPlaybackManager mediaPlaybackManager;

void emberAfMediaPlaybackClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: MediaPlayback::SetDefaultDelegate");
    MediaPlayback::SetDefaultDelegate(endpoint, &mediaPlaybackManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_TARGET_NAVIGATOR_SERVER
#include "target-navigator/TargetNavigatorManager.h"
static TargetNavigatorManager targetNavigatorManager;

void emberAfTargetNavigatorClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: TargetNavigator::SetDefaultDelegate");
    TargetNavigator::SetDefaultDelegate(endpoint, &targetNavigatorManager);
}
#endif

#ifdef MATTER_DM_PLUGIN_WAKE_ON_LAN_SERVER
#include "wake-on-lan/WakeOnLanManager.h"
static WakeOnLanManager wakeOnLanManager;

void emberAfWakeOnLanClusterInitCallback(EndpointId endpoint)
{
    ChipLogProgress(Zcl, "TV Linux App: WakeOnLanManager::SetDefaultDelegate");
    WakeOnLan::SetDefaultDelegate(endpoint, &wakeOnLanManager);
}
#endif
