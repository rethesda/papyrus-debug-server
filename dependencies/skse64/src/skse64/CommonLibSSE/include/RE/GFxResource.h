#pragma once

#include "RE/GAtomic.h"  // GAtomicInt
#include "RE/GFxResourceKey.h"  // GFxResourceKey
#include "RE/GNewOverrideBase.h"  // NewOverrideBase
#include "RE/GStats.h"  // GStatGroups


namespace RE
{
	class GFxResourceLibBase;
	class GFxResourceReport;


	// Resource is an interface for casting to different types of resources.
	class GFxResource : public GNewOverrideBase<GStatGroups::kGStat_Default_Mem>
	{
		friend class GFxResourceWeakLib;
	public:
		// Different types of resources.
		enum class ResourceType
		{
			// Set this bit if CharacterDef
			kCharacterDefBit = 1 << 7,

			// Non-character types
			kNone = 0,
			kImage,
			kFont,
			// Internal
			kMovieDef,
			kSoundSample,

			// GFxCharacterDef derived types
			kMovieDataDef = kCharacterDefBit | 0,
			kButtonDef,
			kTextDef,
			kEditTextDef,
			kSpriteDef,
			kShapeDef,
			kVideoDef,

			// Mask and shift applied to store ResourceType in type code
			kTypeCode_Mask = 0xFF00,
			kTypeCode_Shift = 8
		};


		// An enumeration listing the attributes of the image resource to use such as bitmap, gradient or font texture etc.
		enum class ResourceUse
		{
			kNone = 0,
			kBitmap = 1,
			kGradient = 2,
			kFontTexture = 3,
			kSoundSample = 4,

			// Use mask within TypeCode
			kTypeCode_Mask = 0xFF
		};


		GFxResource();
		virtual ~GFxResource();										// 00

		// add
		virtual GFxResourceKey		GetKey();						// 01
		virtual UInt32				GetResourceTypeCode() const;	// 02
		virtual GFxResourceReport*	GetResourceReport();			// 03

		static UInt32	MakeTypeCode(ResourceType a_resourceType, ResourceUse a_resourceUse = ResourceUse::kNone);	// Creates a resource type code which is a combination of ResourceType and ResourceUse.

		void			AddRef();																					// Thread-safe reference count implementation; increments the reference count.
		bool			AddRef_NotZero();																			// Thread-safe reference count implementation ; increments a reference count if it is not zero.
		SInt32			GetRefCount() const;																		// Thread-Safe reference count implementation; returns the reference count.
		void			SetOwnerResourceLib(GFxResourceLibBase* a_lib);												// Assigns owner library for resource.
		ResourceType	GetResourceType() const;																	// Obtains the resource type.
		ResourceUse		GetResourceUse() const;																		// Obtains the type of resource use.

	protected:
		// members
		GAtomicInt<SInt32>	_refCount;	// 10
		UInt32				_pad14;		// 14
		GFxResourceLibBase*	_lib;		// 18
	};
	STATIC_ASSERT(sizeof(GFxResource) == 0x18);
}
