#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BGSAttachParentArray.h"
#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSForcedLocRefType.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSMod/Template/Items.h"
#include "RE/BGSModelMaterialSwap.h"
#include "RE/BGSNativeTerminalForm.h"
#include "RE/BGSNavmeshableObject.h"
#include "RE/BGSOpenCloseForm.h"
#include "RE/BGSPreviewTransform.h"
#include "RE/BGSPropertySheet.h"
#include "RE/BGSSoundTagComponent.h"
#include "RE/BGSTerminal.h"
#include "RE/BGSTypedKeywordValueArray.h"
#include "RE/BSCoreTypes.h"
#include "RE/BSFixedString.h"
#include "RE/BSGlobalStringTable.h"
#include "RE/BSHandleRefObject.h"
#include "RE/BSInputEventUser.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSLock.h"
#include "RE/BSScript/Array.h"
#include "RE/BSScript/ArrayTypeTraits.h"
#include "RE/BSScript/CommonTypeTraits.h"
#include "RE/BSScript/CompiledScriptLoader.h"
#include "RE/BSScript/ErrorLogger.h"
#include "RE/BSScript/ICachedErrorMessage.h"
#include "RE/BSScript/IClientVM.h"
#include "RE/BSScript/IComplexType.h"
#include "RE/BSScript/IFindBoundObjectFunctor.h"
#include "RE/BSScript/IFunction.h"
#include "RE/BSScript/IHandleReaderWriter.h"
#include "RE/BSScript/ILoader.h"
#include "RE/BSScript/IMemoryPagePolicy.h"
#include "RE/BSScript/Internal/AutoPropGetFunction.h"
#include "RE/BSScript/Internal/AutoPropSetFunction.h"
#include "RE/BSScript/Internal/CachedErrorMessageImpl.h"
#include "RE/BSScript/Internal/CodeTasklet.h"
#include "RE/BSScript/Internal/FunctionMessage.h"
#include "RE/BSScript/Internal/IFuncCallQuery.h"
#include "RE/BSScript/Internal/NativeFunctionStub.h"
#include "RE/BSScript/Internal/RawFuncCallQuery.h"
#include "RE/BSScript/Internal/ScriptFunction.h"
#include "RE/BSScript/Internal/SuspendedStack.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/IObjectProcessor.h"
#include "RE/BSScript/IProfilePolicy.h"
#include "RE/BSScript/ISavePatcherInterface.h"
#include "RE/BSScript/IStackCallbackFunctor.h"
#include "RE/BSScript/IStackCallbackSaveInterface.h"
#include "RE/BSScript/IStore.h"
#include "RE/BSScript/ITypeLinkedCallback.h"
#include "RE/BSScript/IVirtualMachine.h"
#include "RE/BSScript/IVMDebugInterface.h"
#include "RE/BSScript/IVMObjectBindInterface.h"
#include "RE/BSScript/IVMSaveLoadInterface.h"
#include "RE/BSScript/LinkerProcessor.h"
#include "RE/BSScript/LogEvent.h"
#include "RE/BSScript/NativeFunction.h"
#include "RE/BSScript/NativeLatentFunction.h"
#include "RE/BSScript/NF_util/NativeFunctionBase.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/ObjectBindPolicy.h"
#include "RE/BSScript/ObjectTypeInfo.h"
#include "RE/BSScript/ObjectTypeTraits.h"
#include "RE/BSScript/PackUnpack.h"
#include "RE/BSScript/SimpleAllocMemoryPagePolicy.h"
#include "RE/BSScript/Stack.h"
#include "RE/BSScript/StackFrame.h"
#include "RE/BSScript/StatsEvent.h"
#include "RE/BSScript/Struct.h"
#include "RE/BSScript/StructTypeInfo.h"
#include "RE/BSScript/Type.h"
#include "RE/BSScript/TypeTraits.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSScript/VariableInfo.h"
#include "RE/BSScript/VMArray.h"
#include "RE/BSSpinLock.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTFreeList.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTMessageQueue.h"
#include "RE/BSTSingleton.h"
#include "RE/BSTSmartPointer.h"
#include "RE/Condition.h"
#include "RE/CRC.h"
#include "RE/Fallout.h"
#include "RE/FileHash.h"
#include "RE/FormTypes.h"
#include "RE/GameMenuBase.h"
#include "RE/GameScript/BaseHandleReaderWriter.h"
#include "RE/GameScript/BasicEventHandler.h"
#include "RE/GameScript/CombatEventHandler.h"
#include "RE/GameScript/ConcreteDelayFunctorFactory.h"
#include "RE/GameScript/CustomEventHandler.h"
#include "RE/GameScript/DataFileHandleReaderWriter.h"
#include "RE/GameScript/DelayFunctor.h"
#include "RE/GameScript/DelayFunctorFactory.h"
#include "RE/GameScript/DispatchAndClean.h"
#include "RE/GameScript/DistanceEventHandler.h"
#include "RE/GameScript/FragmentEventHandler.h"
#include "RE/GameScript/HandlePolicy.h"
#include "RE/GameScript/Internal/AnimationCallbacks.h"
#include "RE/GameScript/Internal/IProfileCallQuery.h"
#include "RE/GameScript/Internal/LOSDetectionEventData.h"
#include "RE/GameScript/Internal/LOSDirectEventData.h"
#include "RE/GameScript/Internal/LOSEventData.h"
#include "RE/GameScript/InventoryEventHandler.h"
#include "RE/GameScript/LOSEventHandler.h"
#include "RE/GameScript/MenuEventHandler.h"
#include "RE/GameScript/PathingCallbackMgr.h"
#include "RE/GameScript/Profiler.h"
#include "RE/GameScript/QuestCallbackMgr.h"
#include "RE/GameScript/SaveFileHandleReaderWriter.h"
#include "RE/GameScript/SavePatcher.h"
#include "RE/GameScript/SingleActorArgument.h"
#include "RE/GameScript/SingleObjectRefrHandleArgument.h"
#include "RE/GameScript/SingleSimpleArgument.h"
#include "RE/GameScript/SleepEventHandler.h"
#include "RE/GameScript/SoundCallbackMgr.h"
#include "RE/GameScript/Store.h"
#include "RE/GameScript/TeleportEventHandler.h"
#include "RE/GameScript/TimerEventHandler.h"
#include "RE/GameScript/TrackedStatsEventHandler.h"
#include "RE/GameScript/WaitEventHandler.h"
#include "RE/GameVM.h"
#include "RE/IKeywordFormBase.h"
#include "RE/IMenu.h"
#include "RE/Memory.h"
#include "RE/NiRefObject.h"
#include "RE/Offset.h"
#include "RE/Scaleform/AllocInfo.h"
#include "RE/Scaleform/AtomicInt.h"
#include "RE/Scaleform/AtomicValueBase.h"
#include "RE/Scaleform/GFx/ASMovieRootBase.h"
#include "RE/Scaleform/GFx/ASSupport.h"
#include "RE/Scaleform/GFx/CharacterDef.h"
#include "RE/Scaleform/GFx/FileTypeConstants.h"
#include "RE/Scaleform/GFx/FocusMovedType.h"
#include "RE/Scaleform/GFx/FunctionHandler.h"
#include "RE/Scaleform/GFx/MemoryParams.h"
#include "RE/Scaleform/GFx/Movie.h"
#include "RE/Scaleform/GFx/MovieDef.h"
#include "RE/Scaleform/GFx/MovieImpl.h"
#include "RE/Scaleform/GFx/PlayerStats.h"
#include "RE/Scaleform/GFx/PlayState.h"
#include "RE/Scaleform/GFx/Resource.h"
#include "RE/Scaleform/GFx/ResourceID.h"
#include "RE/Scaleform/GFx/ResourceKey.h"
#include "RE/Scaleform/GFx/State.h"
#include "RE/Scaleform/GFx/StateBag.h"
#include "RE/Scaleform/GFx/TagType.h"
#include "RE/Scaleform/GFx/Value.h"
#include "RE/Scaleform/GFx/Viewport.h"
#include "RE/Scaleform/List.h"
#include "RE/Scaleform/ListNode.h"
#include "RE/Scaleform/Lock.h"
#include "RE/Scaleform/Memory.h"
#include "RE/Scaleform/MemoryHeap.h"
#include "RE/Scaleform/NewOverrideBase.h"
#include "RE/Scaleform/Ptr.h"
#include "RE/Scaleform/RefCountBase.h"
#include "RE/Scaleform/RefCountBaseStatImpl.h"
#include "RE/Scaleform/RefCountImpl.h"
#include "RE/Scaleform/RefCountImplCore.h"
#include "RE/Scaleform/Render/Color.h"
#include "RE/Scaleform/Render/Constants.h"
#include "RE/Scaleform/Render/Cxform.h"
#include "RE/Scaleform/Render/Matrix2x4.h"
#include "RE/Scaleform/Render/Matrix2x4Data.h"
#include "RE/Scaleform/Render/Matrix3x4.h"
#include "RE/Scaleform/Render/Matrix3x4Data.h"
#include "RE/Scaleform/Render/Matrix4x4.h"
#include "RE/Scaleform/Render/Matrix4x4Data.h"
#include "RE/Scaleform/Render/Point.h"
#include "RE/Scaleform/Render/Rect.h"
#include "RE/Scaleform/Render/RectData.h"
#include "RE/Scaleform/Render/Viewport.h"
#include "RE/Scaleform/SFTypes.h"
#include "RE/Scaleform/StatBag.h"
#include "RE/Scaleform/Stats.h"
#include "RE/Scaleform/SysAlloc.h"
#include "RE/Scaleform/SysAllocBase.h"
#include "RE/Scaleform/SysAllocBase_SingletonSupport.h"
#include "RE/Scaleform/SysAllocMalloc.h"
#include "RE/Scaleform/SysAllocPaged.h"
#include "RE/Scaleform/ThreadID.h"
#include "RE/SWFToCodeFunctionHandler.h"
#include "RE/TerminalMenu.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESBoundObject.h"
#include "RE/TESDataHandler.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESFurniture.h"
#include "RE/TESInitScriptEvent.h"
#include "RE/TESMagicTargetForm.h"
#include "RE/TESModel.h"
#include "RE/TESObject.h"
#include "RE/TESObjectACTI.h"