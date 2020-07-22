#ifndef __MODULE_MODEL__
#define __MODULE_MODEL__

module;
#include "../Core/Core.h"

#include "Vars.h"
export module ModuleName(Model);

import ModuleName(Config);
import ModuleName(File);
import ModuleName(Internal);

#ifdef __INTELLISENSE__
#include "Config.ixx"
#include "File.ixx"
#include "Internal.ixx"
#endif

//void old_RegisterModel
//(
//	byte8 * dest,
//	byte8 * modelFile,
//	byte8 * textureFile
//)
//{
//	func_8B470(dest, 1);
//	func_89960(dest, modelFile, textureFile);
//}
//
//void old_RegisterShadow
//(
//	byte8 * dest,
//	byte8 * buffer,
//	byte8 * file
//)
//{
//	byte8 * addr = 0;
//
//	addr = func_89DE0(dest);
//	func_8BC60(buffer, addr, file);
//	addr = func_89DE0(dest);
//	func_305D80(addr);
//}
//
//void old_RegisterPhysics
//(
//	byte8 * dest,
//	byte8 * buffer,
//	byte8 * file
//)
//{
//	uint32 count = 0;
//
//	count = func_2C9F40(file);
//
//	for_all(uint32, index, count)
//	{
//		func_2CA1D0(dest, buffer, file, index);
//		dest += 0xF0; // @Todo: Change to Size_240.
//	}
//}
//










inline void RegisterModel
(
	ModelData & modelData,
	byte8 * modelFile,
	byte8 * textureFile
)
{
	func_8B470
	(
		modelData,
		1
	);
	func_89960
	(
		modelData,
		modelFile,
		textureFile
	);
}

inline void RegisterShadow
(
	ModelData & modelData,
	ShadowData & shadowData,
	byte8 * shadowFile
)
{
	auto dest = func_89DE0(modelData);
	func_8BC60
	(
		shadowData,
		dest,
		shadowFile
	);
	//dest = func_89DE0(modelData);
	func_305D80(dest);
}

inline void RegisterPhysics
(
	byte8 * physicsFile,
	PhysicsData * physicsData,
	void * physicsMetadata
)
{
	auto count = func_2C9F40(physicsFile);
	if (count == 0)
	{
		return;
	}
	for_all(uint32, index, count)
	{
		func_2CA1D0
		(
			physicsData[index],
			physicsMetadata,
			physicsFile,
			index
		);
	}
}

//template <typename T>
//void LinkModelPhysicsData
//(
//	T & actorData,
//	DevilModelMetadata & devilModelMetadata,
//	DevilSubmodelMetadata & devilSubmodelMetadata,
//	uint8 devilModelPhysicsDataIndex,
//	uint8 modelPhysicsMetadataIndex,
//	uint8 devilModelPhysicsMetadataIndex
//)
//{
//	uint8 devilModelIndex = (devilModelMetadata.modelIndex == 1) ? 0 : 1;
//
//	auto & devilModelPhysicsData = actorData.devilModelPhysicsData[devilSubmodelMetadata.devilSubmodelIndex][devilModelPhysicsDataIndex];
//
//	auto modelPhysicsMetadataAddr = actorData.modelPhysicsMetadata[devilModelMetadata.modelIndex][(devilModelMetadata.modelPhysicsMetadataIndex + modelPhysicsMetadataIndex)];
//	if (!modelPhysicsMetadataAddr)
//	{
//		return;
//	}
//	auto & modelPhysicsMetadata = *modelPhysicsMetadataAddr;
//
//	auto devilModelPhysicsMetadataAddr = actorData.devilModelPhysicsMetadata[devilModelIndex][(devilSubmodelMetadata.devilModelPhysicsMetadataIndex + devilModelPhysicsMetadataIndex)];
//	if (!devilModelPhysicsMetadataAddr)
//	{
//		return;
//	}
//	auto & devilPhysicsMetadata = *devilModelPhysicsMetadataAddr;
//
//	devilModelPhysicsData.enable = 1;
//	devilModelPhysicsData.physicsData = modelPhysicsMetadata.physicsData;
//	memcpy(devilModelPhysicsData.data, (appBaseAddr + 0x35D580), 64);
//
//	devilPhysicsMetadata.devilPhysicsData = &devilModelPhysicsData;
//}





















/*
human

func_2CA1D0
(
actorData.var_A210,
actorData.var_A0D0,
physicsFile,
index
);

devil

func_2CA1D0
(
actorData.var_A540[devilSubmodelIndex],
&actorData.devilPhysicsMetadata[devilModelIndex][devilPhysicsMetadataIndex],
physicsFile,
index
);
*/










































// @Todo: Add Shadow.

export void ResetModel(ModelData & modelData)
{
	func_897B0(modelData);
	func_89450(modelData);
	memset(modelData, 0, sizeof(ModelData));
	func_89270(modelData);
}



















//void CopyBaseVertices(MODEL_METADATA * modelMetadata)
//{
//	auto g_vertices = reinterpret_cast<vec4 *>(appBaseAddr + 0x58B260);
//
//	for_all(uint8, index, 6)
//	{
//		uint8 off = (index * 3);
//		modelMetadata[index].count = 4;
//		modelMetadata[index].vertices[0] = g_vertices[(off + 0)];
//		modelMetadata[index].vertices[1] = g_vertices[(off + 1)];
//		modelMetadata[index].vertices[2] = g_vertices[(off + 2)];
//	}
//}
//
//void CopyAmuletVertices(MODEL_METADATA * modelMetadata)
//{
//	auto g_vertices = reinterpret_cast<vec4 *>(appBaseAddr + 0x58B260);
//
//	modelMetadata[0].count = 4;
//	modelMetadata[0].vertices[0] = g_vertices[23];
//	modelMetadata[0].vertices[1] = g_vertices[24];
//	modelMetadata[0].vertices[2] = g_vertices[25];
//}
//
//void CopyCoatVertices(byte8 * dest)
//{
//	auto g_vertices = reinterpret_cast<vec4 *>(appBaseAddr + 0x35D580);
//	auto addr = *reinterpret_cast<byte8 **>(dest);
//	auto vertices = *reinterpret_cast<vec4 **>(addr + 0x108);
//
//	vertices[0] = g_vertices[0];
//	vertices[1] = g_vertices[1];
//	vertices[2] = g_vertices[2];
//	vertices[3] = g_vertices[3];
//}











template <typename T>
void UpdateModelFunctionDante(T & actorData)
{
	auto costume = actorData.costume;
	if (costume >= MAX_COSTUME_DANTE)
	{
		costume = 0;
	}
	auto costumeFileId = costumeFileIdsDante[costume];
	auto coat =
	(
		(costume == COSTUME_DANTE_DEFAULT                           ) ||
		(costume == COSTUME_DANTE_DEFAULT_TORN                      ) ||
		(costume == COSTUME_DANTE_DMC1                              ) ||
		(costume == COSTUME_DANTE_SPARDA                            ) ||
		(costume == COSTUME_DANTE_DEFAULT_TORN_INFINITE_MAGIC_POINTS) ||
		(costume == COSTUME_DANTE_SPARDA_INFINITE_MAGIC_POINTS      )
	)
	? true : false;

	if (actorData.newForceFiles)
	{
		switch (actorData.newForceFilesCharacter)
		{
		case CHAR_BOB:
		{
			if (costume >= MAX_COSTUME_BOB)
			{
				costume = 0;
			}
			costumeFileId = costumeFileIdsBob[costume];
			coat = false;
			break;
		}
		case CHAR_LADY:
		{
			if (costume >= MAX_COSTUME_LADY)
			{
				costume = 0;
			}
			costumeFileId = costumeFileIdsLady[costume];
			coat = false;
			break;
		}
		case CHAR_VERGIL:
		{
			if (costume >= MAX_COSTUME_VERGIL)
			{
				costume = 0;
			}
			costumeFileId = costumeFileIdsVergil[costume];
			coat =
			(
				(costume == COSTUME_VERGIL_DEFAULT                      ) ||
				(costume == COSTUME_VERGIL_DEFAULT_INFINITE_MAGIC_POINTS) ||
				(costume == COSTUME_VERGIL_SPARDA                       ) ||
				(costume == COSTUME_VERGIL_SPARDA_INFINITE_MAGIC_POINTS )
			)
			? true : false;
			break;
		}
		}
	}

	auto & file = File_staticFiles[costumeFileId];

	byte8 * modelFile   = 0;
	byte8 * textureFile = 0;
	byte8 * shadowFile  = 0;
	byte8 * physicsFile = 0;

	uint8 modelIndex    = 0;
	uint8 submodelIndex = 0;

	// Main

	modelFile   = file[1];
	textureFile = file[0];
	shadowFile  = file[8];

	if (actorData.newForceFiles && (actorData.newForceFilesCharacter == CHAR_LADY) && (costume == COSTUME_LADY_LEATHER_JUMPSUIT))
	{
		modelFile   = file[32];
		textureFile = file[31];
		shadowFile  = file[16];
	}

	RegisterModel
	(
		actorData.modelData[modelIndex],
		modelFile,
		textureFile
	);

	RegisterShadow
	(
		actorData.modelData[modelIndex],
		actorData.modelShadowData[modelIndex],
		shadowFile
	);

	{
		auto g_vertices = reinterpret_cast<vec4 *>(appBaseAddr + 0x58B260);

		for_all(uint8, index, 6)
		{
			uint8 off = (index * 3);
			actorData.modelMetadata[index].count = 4;
			actorData.modelMetadata[index].vertices[0] = g_vertices[(off + 0)];
			actorData.modelMetadata[index].vertices[1] = g_vertices[(off + 1)];
			actorData.modelMetadata[index].vertices[2] = g_vertices[(off + 2)];
		}
	}

	// Coat

	modelFile   = file[12];
	textureFile = file[0 ];
	shadowFile  = file[14];
	physicsFile = file[13];

	if (actorData.newForceFiles && (actorData.newForceFilesCharacter == CHAR_LADY) && (costume == COSTUME_LADY_LEATHER_JUMPSUIT))
	{
		modelFile   = file[17];
		textureFile = file[31];
		physicsFile = file[18];
	}

	RegisterModel
	(
		actorData.submodelData[submodelIndex],
		modelFile,
		textureFile
	);

	func_8A000
	(
		actorData.submodelData[submodelIndex],
		0,
		&actorData.submodelPhysicsMetadata
	);

	if (actorData.newForceFiles && (actorData.newForceFilesCharacter == CHAR_LADY))
	{
		return;
	}

	if (coat)
	{
		RegisterShadow
		(
			actorData.submodelData[submodelIndex],
			actorData.submodelShadowData[submodelIndex],
			shadowFile
		);
	}

	actorData.var_9AC0[submodelIndex] = true;

	RegisterPhysics
	(
		physicsFile,
		&actorData.submodelPhysicsData,
		&actorData.submodelPhysicsMetadata
	);

	func_2CA2F0
	(
		actorData.submodelPhysicsData,
		actorData.modelPhysicsMetadataPool[modelIndex],
		(appBaseAddr + 0x58B380),
		actorData.modelMetadata,
		(coat) ? 6 : 1
	);

	if (coat)
	{
		auto g_vertices = reinterpret_cast<vec4 *>(appBaseAddr + 0x35D580);

		actorData.submodelPhysicsMetadata.vertices[0] = g_vertices[0];
		actorData.submodelPhysicsMetadata.vertices[1] = g_vertices[1];
		actorData.submodelPhysicsMetadata.vertices[2] = g_vertices[2];
		actorData.submodelPhysicsMetadata.vertices[3] = g_vertices[3];
	}
	else
	{
		auto g_vertices = reinterpret_cast<vec4 *>(appBaseAddr + 0x58B260);

		actorData.modelMetadata[0].count = 4;
		actorData.modelMetadata[0].vertices[0] = g_vertices[23];
		actorData.modelMetadata[0].vertices[1] = g_vertices[24];
		actorData.modelMetadata[0].vertices[2] = g_vertices[25];
	}
}









export void UpdateModelDante(byte8 * baseAddr)
{
	LogFunction(baseAddr);

	auto & actorData = *reinterpret_cast<ACTOR_DATA_DANTE *>(baseAddr);

	UpdateModelFunctionDante(actorData);
}










//template <typename T>
//void LinkPhysics
//(
//	T & actorData,
//	DevilPhysicsData & devilPhysicsData,
//	uint8 physicsIndex,
//	uint8 devilPhysicsIndex
//)
//{
//	uint8 modelIndex = 1;
//	uint8 devilModelIndex = 0;
//
//	auto & devilPhysicsMetadata = *actorData.devilPhysicsMetadata[devilModelIndex][devilPhysicsIndex];
//	devilPhysicsMetadata.devilPhysicsData = &devilPhysicsData;
//
//	devilPhysicsData.enable = 1;
//
//	auto & physicsMetadata = *actorData.physicsMetadata[modelIndex][physicsIndex];
//	devilPhysicsData.physicsData = physicsMetadata.physicsData;
//
//	memcpy(devilPhysicsData.data, (appBaseAddr + 0x35D580), 64);
//}
































export template <typename T>
void UpdateDevilModelFunctionDante
(
	T & actorData,
	uint8 devil,
	uint8 devilModelIndex
)
{
	auto devilFileId = devilFileIdsDante[devil];

	auto & file = File_staticFiles[devilFileId];

	byte8 * modelFile   = 0;
	byte8 * textureFile = 0;
	byte8 * shadowFile  = 0;
	byte8 * physicsFile = 0;

	auto & devilModelMetadata = actorData.devilModelMetadata[devil];

	uint8 modelIndex                = (devilModelIndex == 0) ? 1  : 2;
	uint8 modelPhysicsMetadataIndex = 0;

	uint8 submodelIndex                  = (devilModelIndex == 0) ? 1 : 3;
	uint8 devilModelPhysicsMetadataIndex = 0;
	uint8 devilSubmodelIndex             = (devilModelIndex == 0) ? 0 : 2;

	auto LinkModelPhysicsData = [&]
	(
		uint8 _devilModelPhysicsDataIndex,
		uint8 _modelPhysicsMetadataIndex,
		uint8 _devilModelPhysicsMetadataIndex
	)
	{
		auto & devilModelPhysicsData = actorData.devilModelPhysicsData[devilSubmodelIndex][_devilModelPhysicsDataIndex];

		auto modelPhysicsMetadataAddr = actorData.modelPhysicsMetadataPool[modelIndex][(modelPhysicsMetadataIndex + _modelPhysicsMetadataIndex)];
		if (!modelPhysicsMetadataAddr)
		{
			return;
		}
		auto & modelPhysicsMetadata = *modelPhysicsMetadataAddr;

		auto devilModelPhysicsMetadataAddr = actorData.devilModelPhysicsMetadataPool[devilModelIndex][(devilModelPhysicsMetadataIndex + _devilModelPhysicsMetadataIndex)];
		if (!devilModelPhysicsMetadataAddr)
		{
			return;
		}
		auto & devilPhysicsMetadata = *devilModelPhysicsMetadataAddr;

		devilModelPhysicsData.enable = 1;
		devilModelPhysicsData.physicsData = modelPhysicsMetadata.physicsData;
		memcpy(devilModelPhysicsData.data, (appBaseAddr + 0x35D580), 64);

		devilPhysicsMetadata.devilPhysicsData = &devilModelPhysicsData;
	};

	actorData.devilModels[modelIndex] = devil;

	// Main

	modelFile   = file[1];
	textureFile = file[0];

	if (devil == DEVIL_DANTE_AGNI_RUDRA)
	{
		shadowFile  = file[2];
	}
	else if
	(
		(devil == DEVIL_DANTE_CERBERUS) ||
		(devil == DEVIL_DANTE_BEOWULF ) ||
		(devil == DEVIL_DANTE_SPARDA  )
	)
	{
		shadowFile  = file[4];
	}
	else if
	(
		(devil == DEVIL_DANTE_REBELLION) ||
		(devil == DEVIL_DANTE_NEVAN    )
	)
	{
		shadowFile  = file[6];
	}

	RegisterModel
	(
		actorData.modelData[modelIndex],
		modelFile,
		textureFile
	);

	func_1EF040
	(
		actorData,
		modelIndex
	);

	RegisterShadow
	(
		actorData.modelData[modelIndex],
		actorData.modelShadowData[modelIndex],
		shadowFile
	);

	devilModelMetadata.modelIndex = modelIndex;
	devilModelMetadata.modelPhysicsMetadataIndex = ((modelIndex * 24) + modelPhysicsMetadataIndex);

	if (devil == DEVIL_DANTE_AGNI_RUDRA)
	{
		return;
	}

	// Wings

	modelFile   = file[2];
	textureFile = file[0];
	physicsFile = file[3];

	if
	(
		(devil == DEVIL_DANTE_REBELLION) ||
		(devil == DEVIL_DANTE_NEVAN    )
	)
	{
		shadowFile = file[7];
	}
	else if
	(
		(devil == DEVIL_DANTE_CERBERUS) ||
		(devil == DEVIL_DANTE_BEOWULF ) ||
		(devil == DEVIL_DANTE_SPARDA  )
	)
	{
		shadowFile = file[5];
	}

	RegisterModel
	(
		actorData.submodelData[submodelIndex],
		modelFile,
		textureFile
	);

	func_8A000
	(
		actorData.submodelData[submodelIndex],
		0,
		&actorData.devilModelPhysicsMetadataPool[devilModelIndex][devilModelPhysicsMetadataIndex]
	);

	RegisterShadow
	(
		actorData.submodelData[submodelIndex],
		actorData.submodelShadowData[submodelIndex],
		shadowFile
	);

	actorData.var_9AC0[submodelIndex] = true;

	RegisterPhysics
	(
		physicsFile,
		&actorData.devilSubmodelPhysicsData[devilSubmodelIndex],
		&actorData.devilModelPhysicsMetadataPool[devilModelIndex][devilModelPhysicsMetadataIndex]
	);

	if
	(
		(devil == DEVIL_DANTE_REBELLION) ||
		(devil == DEVIL_DANTE_NEVAN    )
	)
	{
		LinkModelPhysicsData(0, 3, 1);
		LinkModelPhysicsData(1, 2, 12);
	}
	else if
	(
		(devil == DEVIL_DANTE_CERBERUS) ||
		(devil == DEVIL_DANTE_BEOWULF )
	)
	{
		LinkModelPhysicsData(0, 3, 1);
		LinkModelPhysicsData(1, 6 , 2);
		LinkModelPhysicsData(2, 10, 8);
	}

	devilModelMetadata.devilSubmodelMetadata[0].submodelIndex                  = submodelIndex;
	devilModelMetadata.devilSubmodelMetadata[0].devilModelPhysicsMetadataIndex = ((devilModelIndex * 36) + devilModelPhysicsMetadataIndex);
	devilModelMetadata.devilSubmodelMetadata[0].devilSubmodelIndex             = devilSubmodelIndex;

	submodelIndex++;
	devilModelPhysicsMetadataIndex += 9;
	devilSubmodelIndex++;

	// Coat

	if
	(
		!(
			(devil == DEVIL_DANTE_REBELLION) ||
			(devil == DEVIL_DANTE_NEVAN    )
		)
	)
	{
		return;
	}

	modelFile   = file[4];
	textureFile = file[0];
	shadowFile  = file[8];
	physicsFile = file[5];

	RegisterModel
	(
		actorData.submodelData[submodelIndex],
		modelFile,
		textureFile
	);

	func_8A000
	(
		actorData.submodelData[submodelIndex],
		0,
		&actorData.devilModelPhysicsMetadataPool[devilModelIndex][devilModelPhysicsMetadataIndex]
	);

	RegisterShadow
	(
		actorData.submodelData[submodelIndex],
		actorData.submodelShadowData[submodelIndex],
		shadowFile
	);

	actorData.var_9AC0[submodelIndex] = true;

	RegisterPhysics
	(
		physicsFile,
		&actorData.devilSubmodelPhysicsData[devilSubmodelIndex],
		&actorData.devilModelPhysicsMetadataPool[devilModelIndex][devilModelPhysicsMetadataIndex]
	);

	func_2CA2F0
	(
		actorData.devilSubmodelPhysicsData[devilSubmodelIndex],
		actorData.modelPhysicsMetadataPool[modelIndex],
		(appBaseAddr + 0x58B380),
		actorData.modelMetadata,
		6
	);

	LinkModelPhysicsData(0, 2 , 1);
	LinkModelPhysicsData(1, 14, 2);

	devilModelMetadata.devilSubmodelMetadata[1].submodelIndex                   = submodelIndex;
	devilModelMetadata.devilSubmodelMetadata[1].devilModelPhysicsMetadataIndex  = ((devilModelIndex * 36) + devilModelPhysicsMetadataIndex);
	devilModelMetadata.devilSubmodelMetadata[1].devilSubmodelIndex              = devilSubmodelIndex;
}

















void UpdateDevilModelDante(ACTOR_DATA_DANTE & actorData)
{
	LogFunction(actorData.operator byte8 *());
	UpdateDevilModelFunctionDante(actorData, 0, 0);
}



























//Vector devilAuras<byte8 *>;

export Vector<byte8 *> devilAuras;















void CreateDevilAura(byte8 * baseAddr)
{
	LogFunction(baseAddr);

	if (!baseAddr)
	{
		return;
	}

	devilAuras.Push(baseAddr);






	//auto actorBaseAddr = *reinterpret_cast<byte8 **>(baseAddr + 0xC0);
	//if (!actorBaseAddr)
	//{
	//	return;
	//}
	//auto & actorData = *reinterpret_cast<ACTOR_DATA *>(actorBaseAddr);
	//actorData.newDevilAura = baseAddr;
}




void EnterDevilForm(byte8 * baseAddr)
{
	LogFunction(baseAddr);


	if (!baseAddr)
	{
		return;
	}

	//auto & actorData = *reinterpret_cast<byte8 **>(baseAddr);

	auto & actorData = *reinterpret_cast<ACTOR_DATA *>(baseAddr);




	//func_1F94D0(actorData, 1);











}

void LeaveDevilForm(byte8 * baseAddr)
{
	LogFunction(baseAddr);

	if (!baseAddr)
	{
		return;
	}
	auto & actorData = *reinterpret_cast<ACTOR_DATA *>(baseAddr);
	//if (!actorData.newDevilAura)
	//{
	//	return;
	//}


	if (!devilAuras[0])
	{
		return;
	}

	
	
	auto & actorBaseAddr = *reinterpret_cast<byte8 **>(devilAuras[0] + 0xC0);

	Log("actorBaseAddr %llX", actorBaseAddr);

	//actorBaseAddr = actorData;





	Log("PopFirst");

	devilAuras.PopFirst();










	//auto & actorBaseAddr = *reinterpret_cast<byte8 **>(actorData.newDevilAura + 0xC0);









	//actorData.newDevilAura = 0;

















	//func_1F94D0(actorData, 2);
}









export void Model_Init()
{
	LogFunction();



	//if (!devilAuras.Init(512))
	//{
	//	Log("devilAuras.Init failed.");
	//	return;
	//}









	//{
	//	constexpr byte8 sect1[] =
	//	{
	//		mov_rcx_rsi,
	//	};
	//	auto func = CreateFunction(UpdateDevilModelDante, (appBaseAddr + 0x21344F), true, true, 0, sizeof(sect1));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	//WriteJump((appBaseAddr + 0x213167), func.addr, 2);
	//}

	// Force Only Rebellion
	//WriteJump((appBaseAddr + 0x214B29), (appBaseAddr + 0x21344F));


	//return;





	{
		auto func = CreateFunction(UpdateModelDante);
		WriteCall((appBaseAddr + 0x212CB3), func.addr);
		/*
		dmc3.exe+212CB3 - E8 98200000       - call dmc3.exe+214D50
		dmc3.exe+212CB8 - 48 8D 86 A0380000 - lea rax,[rsi+000038A0]
		*/
	}



	// Dante Model Partition Updates
	{
		constexpr byte8 sect0[] =
		{
			0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
			0x74, 0x05,                               // je short
			0xE8, 0x00, 0x00, 0x00, 0x00,             // call dmc3.exe+2169F0
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x21557C), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newForceFiles);
		WriteCall((func.sect0 + 9), (appBaseAddr + 0x2169F0));
		WriteJump((appBaseAddr + 0x215577), func.addr);
		/*
		dmc3.exe+215577 - E8 74140000       - call dmc3.exe+2169F0
		dmc3.exe+21557C - 48 81 C7 40750000 - add rdi,00007540
		*/
	}


	// Vergil Model Parition Updates
	{
		constexpr byte8 sect0[] =
		{
			0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
			0x74, 0x05,                               // je short
			0xE8, 0x00, 0x00, 0x00, 0x00,             // call dmc3.exe+223420
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x222861), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newForceFiles);
		WriteCall((func.sect0 + 9), (appBaseAddr + 0x223420));
		WriteJump((appBaseAddr + 0x22285C), func.addr);
		/*
		dmc3.exe+22285C - E8 BF0B0000       - call dmc3.exe+223420
		dmc3.exe+222861 - 48 8D B7 40750000 - lea rsi,[rdi+00007540]
		*/
	}

	// Ebony Ivory Position Update
	{
		constexpr byte8 sect0[] =
		{
			0x0F, 0xB6, 0x90, 0x9E, 0x3E, 0x00, 0x00, // movzx edx,byte ptr [rax+00003E9E]
			0x80, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rax+0000B8C0],01
			0x0F, 0x84, 0x00, 0x00, 0x00, 0x00,       // je dmc3.exe+22B7E2
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x22B616), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 9) = offsetof(ACTOR_DATA, newForceFiles);
		WriteAddress((func.sect0 + 0xE), (appBaseAddr + 0x22B7E2), 6);
		WriteJump((appBaseAddr + 0x22B60F), func.addr, 2);
		/*
		dmc3.exe+22B60F - 0FB6 90 9E3E0000 - movzx edx,byte ptr [rax+00003E9E]
		dmc3.exe+22B616 - 8D 42 FD         - lea eax,[rdx-03]
		*/
	}


	// Dante Coat Update
	{
		constexpr byte8 sect0[] =
		{
			0x80, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rsi+0000B8C0],01
			0x75, 0x12,                               // jne short
			0x80, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, // cmp byte ptr [rsi+0000B8C0],02
			0x75, 0x09,                               // jne short
			0x48, 0x8B, 0x96, 0xA8, 0x18, 0x00, 0x00, // mov rdx,[rsi+000018A8]
			0xEB, 0x07,                               // jmp short
			0x48, 0x8B, 0x96, 0x98, 0x18, 0x00, 0x00, // mov rdx,[rsi+00001898]
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x2120CB), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newForceFiles);
		*reinterpret_cast<uint32 *>(func.sect0 + 0xB) = offsetof(ACTOR_DATA, newForceFilesCharacter);
		*reinterpret_cast<uint8 *>(func.sect0 + 0xF) = CHAR_LADY;
		WriteJump((appBaseAddr + 0x2120C4), func.addr, 2);
		/*
		dmc3.exe+2120C4 - 48 8B 96 98180000 - mov rdx,[rsi+00001898]
		dmc3.exe+2120CB - 48 8D 8E 40750000 - lea rcx,[rsi+00007540]
		*/
	}























	//// Devil Coat Update
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
	//		0x75, 0x01,                               // jne short
	//		0xC3,                                     // ret
	//		0x40, 0x57,                               // push rdi
	//		0x48, 0x83, 0xEC, 0x30,                   // sub rsp,30
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x216686), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newForceFiles);
	//	//WriteJump((appBaseAddr + 0x216680), func.addr, 1);
	//	/*
	//	dmc3.exe+216680 - 40 57       - push rdi
	//	dmc3.exe+216682 - 48 83 EC 30 - sub rsp,30
	//	dmc3.exe+216686 - 48 8B F9    - mov rdi,rcx
	//	*/
	//}





	//// Dante Coat Position Update
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
	//		0x74, 0x16,                               // je short
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
	//		0x75, 0x0D,                               // jne short
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, // cmp byte ptr [rcx+0000B8C0],02
	//		0x0F, 0x84, 0x00, 0x00, 0x00, 0x00,       // je dmc3.exe+2191D0
	//		0x40, 0x56,                               // push rsi
	//		0x48, 0x83, 0xEC, 0x20,                   // sub rsp,20
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x212076), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, devil);
	//	*reinterpret_cast<uint32 *>(func.sect0 + 0xB) = offsetof(ACTOR_DATA, newForceFiles);
	//	*reinterpret_cast<uint32 *>(func.sect0 + 0x14) = offsetof(ACTOR_DATA, newForceFilesCharacter);
	//	*reinterpret_cast<uint8 *>(func.sect0 + 0x18) = CHAR_LADY;
	//	WriteAddress((func.sect0 + 0x19), (appBaseAddr + 0x2191D0), 6);
	//	//WriteJump((appBaseAddr + 0x212070), func.addr, 1);
	//	/*
	//	dmc3.exe+212070 - 40 56             - push rsi
	//	dmc3.exe+212072 - 48 83 EC 20       - sub rsp,20
	//	dmc3.exe+212076 - 48 63 81 6C3E0000 - movsxd  rax,dword ptr [rcx+00003E6C]
	//	*/
	//}
























	
	//// Dante Coat Position Update
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
	//		0x75, 0x0E,                               // jne short
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, // cmp byte ptr [rcx+0000B8C0],02
	//		0x75, 0x05,                               // jne short
	//		0xE9, 0x00, 0x00, 0x00, 0x00,             // jmp dmc3.exe+2191D0
	//		0x40, 0x56,                               // push rsi
	//		0x48, 0x83, 0xEC, 0x20,                   // sub rsp,20
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x212076), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newForceFiles);
	//	*reinterpret_cast<uint32 *>(func.sect0 + 0xB) = offsetof(ACTOR_DATA, newForceFilesCharacter);
	//	*reinterpret_cast<uint8 *>(func.sect0 + 0xF) = CHAR_LADY;
	//	WriteJump((func.sect0 + 0x12), (appBaseAddr + 0x2191D0));



	//	//WriteJump((appBaseAddr + 0x212070), func.addr, 1);




	//	/*
	//	dmc3.exe+212070 - 40 56             - push rsi
	//	dmc3.exe+212072 - 48 83 EC 20       - sub rsp,20
	//	dmc3.exe+212076 - 48 63 81 6C3E0000 - movsxd  rax,dword ptr [rcx+00003E6C]
	//	*/
	//}






	//// Dante 7540 Position Update
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x80, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x01, // cmp byte ptr [rcx+0000B8C0],01
	//		0x0F, 0x84, 0x00, 0x00, 0x00, 0x00,       // je dmc3.exe+2191D0
	//		0x40, 0x56,                               // push rsi
	//		0x48, 0x83, 0xEC, 0x20,                   // sub rsp,20
	//	};
	//	auto func = CreateFunction(0, (appBaseAddr + 0x212076), false, true, sizeof(sect0));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newForceLadyFiles);
	//	WriteAddress((func.sect0 + 7), (appBaseAddr + 0x2191D0), 6);
	//	WriteJump((appBaseAddr + 0x212070), func.addr, 1);
	//	/*
	//	dmc3.exe+212070 - 40 56             - push rsi
	//	dmc3.exe+212072 - 48 83 EC 20       - sub rsp,20
	//	dmc3.exe+212076 - 48 63 81 6C3E0000 - movsxd  rax,dword ptr [rcx+00003E6C]
	//	*/
	//}




	// Create Devil Aura
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x48, 0x8B, 0x83, 0xC0, 0x00, 0x00, 0x00, // mov rax,[rbx+000000C0]
	//		0x48, 0x85, 0xC0,                         // test rax,rax
	//		0x74, 0x03,                               // je short
	//		0x48, 0x8B, 0xC8,                         // mov rcx,rax
	//		0xE8, 0x00, 0x00, 0x00, 0x00,             // call dmc3.exe+1FAA90
	//	};
	//	constexpr byte8 sect1[] =
	//	{
	//		mov_rcx_rbx,
	//	};
	//	auto func = CreateFunction(CreateDevilAura, (appBaseAddr + 0x8E45C), true, true, sizeof(sect0), sizeof(sect1));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	WriteCall((func.sect0 + 0xF), (appBaseAddr + 0x1FAA90));
	//	WriteJump((appBaseAddr + 0x8E457), func.addr);
	//	/*
	//	dmc3.exe+8E457 - E8 34C61600 - call dmc3.exe+1FAA90
	//	dmc3.exe+8E45C - 48 8B D0    - mov rdx,rax
	//	*/
	//}





	// Enter Devil Form
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0xC6, 0x87, 0x9B, 0x3E, 0x00, 0x00, 0x01, // mov byte ptr [rdi+00003E9B],01
	//	};
	//	constexpr byte8 sect1[] =
	//	{
	//		mov_rcx_rdi,
	//	};
	//	auto func = CreateFunction(EnterDevilForm, (appBaseAddr + 0x1E7810), true, true, sizeof(sect0), sizeof(sect1));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	WriteJump((appBaseAddr + 0x1E7809), func.addr, 2);
	//	/*
	//	dmc3.exe+1E7809 - C6 87 9B3E0000 01 - mov byte ptr [rdi+00003E9B],01
	//	dmc3.exe+1E7810 - 89 74 24 30       - mov [rsp+30],esi
	//	*/
	//}


	// Leave Devil Form
	//{
	//	constexpr byte8 sect0[] =
	//	{
	//		0x40, 0x88, 0xB7, 0x9B, 0x3E, 0x00, 0x00, // mov [rdi+00003E9B],sil
	//	};
	//	constexpr byte8 sect1[] =
	//	{
	//		mov_rcx_rdi,
	//	};
	//	auto func = CreateFunction(LeaveDevilForm, (appBaseAddr + 0x1E78C6), true, true, sizeof(sect0), sizeof(sect1));
	//	memcpy(func.sect0, sect0, sizeof(sect0));
	//	memcpy(func.sect1, sect1, sizeof(sect1));
	//	WriteJump((appBaseAddr + 0x1E78BF), func.addr, 2);
	//	/*
	//	dmc3.exe+1E78BF - 40 88 B7 9B3E0000 - mov [rdi+00003E9B],sil
	//	dmc3.exe+1E78C6 - 48 8B CF          - mov rcx,rdi
	//	*/
	//}








	// On
	{
		constexpr byte8 sect0[] =
		{
			0x48, 0x8B, 0x83, 0xC0, 0x00, 0x00, 0x00, // mov rax,[rbx+000000C0]
			0x48, 0x85, 0xC0,                         // test rax,rax
			0x74, 0x09,                               // je short
			0x8B, 0x84, 0x90, 0x00, 0x00, 0x00, 0x00, // mov eax,[rax+rdx*4+0000B8C0]
			0xEB, 0x07,                               // jmp short
			0x8B, 0x84, 0x96, 0xC0, 0x2D, 0xC9, 0x00, // mov eax,[rsi+rdx*4+00C92DC0]
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x8DC23), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 0xF) = offsetof(ACTOR_DATA, newEffectIndices);
		WriteJump((appBaseAddr + 0x8DC1C), func.addr, 2);
		/*
		dmc3.exe+8DC1C - 8B 84 96 C02DC900 - mov eax,[rsi+rdx*4+00C92DC0]
		dmc3.exe+8DC23 - 0FA3 C8           - bt eax,ecx
		*/
	}



	// Update
	{
		constexpr byte8 sect0[] =
		{
			0x48, 0x8B, 0x87, 0xC0, 0x00, 0x00, 0x00,       // mov rax,[rdi+000000C0]
			0x48, 0x85, 0xC0,                               // test rax,rax
			0x74, 0x09,                                     // je short
			0x8B, 0x84, 0x90, 0x00, 0x00, 0x00, 0x00,       // mov eax,[rax+rdx*4+0000B8C0]
			0xEB, 0x08,                                     // jmp short
			0x41, 0x8B, 0x84, 0x91, 0xC0, 0x2D, 0xC9, 0x00, // mov eax,[r9+rdx*4+00C92DC0]
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x90D29), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 0xF) = offsetof(ACTOR_DATA, newEffectIndices);
		WriteJump((appBaseAddr + 0x90D21), func.addr, 3);
		/*
		dmc3.exe+90D21 - 41 8B 84 91 C02DC900 - mov eax,[r9+rdx*4+00C92DC0]
		dmc3.exe+90D29 - 0FA3 C8              - bt eax,ecx
		*/
	}





	// Off
	{
		constexpr byte8 sect0[] =
		{
			0x8B, 0x83, 0x00, 0x00, 0x00, 0x00, // mov eax,[rbx+0000B8C0]
			0x8B, 0x8B, 0x00, 0x00, 0x00, 0x00, // mov ecx,[rbx+0000B8C0]
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x1F954E), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newEffectIndices[1]);
		*reinterpret_cast<uint32 *>(func.sect0 + 8) = offsetof(ACTOR_DATA, newEffectIndices[2]);
		WriteJump((appBaseAddr + 0x1F9542), func.addr, 1);
		/*
		dmc3.exe+1F9542 - 8B 05 7C98A900 - mov eax,[dmc3.exe+C92DC4]
		dmc3.exe+1F9548 - 8B 0D 7A98A900 - mov ecx,[dmc3.exe+C92DC8]
		dmc3.exe+1F954E - 83 C8 01       - or eax,01
		*/
	}





	{
		constexpr byte8 sect0[] =
		{
			0x89, 0x83, 0x00, 0x00, 0x00, 0x00, // mov [rbx+0000B8C0],eax
			0x89, 0x8B, 0x00, 0x00, 0x00, 0x00, // mov [rbx+0000B8C0],ecx
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x1F9578), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 2) = offsetof(ACTOR_DATA, newEffectIndices[1]);
		*reinterpret_cast<uint32 *>(func.sect0 + 8) = offsetof(ACTOR_DATA, newEffectIndices[2]);
		WriteJump((appBaseAddr + 0x1F956C), func.addr, 1);
		/*
		dmc3.exe+1F956C - 89 05 5298A900 - mov [dmc3.exe+C92DC4],eax
		dmc3.exe+1F9572 - 89 0D 5098A900 - mov [dmc3.exe+C92DC8],ecx
		dmc3.exe+1F9578 - 48 83 C4 20    - add rsp,20
		*/
	}




	{
		constexpr byte8 sect0[] =
		{
			0xD3, 0xE0,                                     // shl eax,cl
			0x48, 0x8B, 0x8F, 0xC0, 0x00, 0x00, 0x00,       // mov rcx,[rdi+000000C0]
			0x48, 0x85, 0xC9,                               // test rcx,rcx
			0x74, 0x09,                                     // je short
			0x31, 0x84, 0x91, 0x00, 0x00, 0x00, 0x00,       // xor [rcx+rdx*4+0000B8C0],eax
			0xEB, 0x08,                                     // jmp short
			0x41, 0x31, 0x84, 0x91, 0xC0, 0x2D, 0xC9, 0x00, // xor [r9+rdx*4+00C92DC0],eax
			0x48, 0x8B, 0xCF,                               // mov rcx,rdi
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x90D57), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		*reinterpret_cast<uint32 *>(func.sect0 + 0x11) = offsetof(ACTOR_DATA, newEffectIndices);
		WriteJump((appBaseAddr + 0x90D4A), func.addr);
		/*
		dmc3.exe+90D4A - D3 E0                - shl eax,cl
		dmc3.exe+90D4C - 48 8B CF             - mov rcx,rdi
		dmc3.exe+90D4F - 41 31 84 91 C02DC900 - xor [r9+rdx*4+00C92DC0],eax
		dmc3.exe+90D57 - 33 D2                - xor edx,edx
		*/
	}





	// Update Effect Position

	{
		constexpr byte8 sect0[] =
		{
			0x48, 0x8B, 0x87, 0xC0, 0x00, 0x00, 0x00, // mov rax,[rdi+000000C0]
			0x48, 0x85, 0xC0,                         // test rax,rax
			0x74, 0x03,                               // je short
			0x48, 0x8B, 0xC8,                         // mov rcx,rax
			0xE8, 0x00, 0x00, 0x00, 0x00,             // call dmc3.exe+1FAA90
		};
		auto func = CreateFunction(0, (appBaseAddr + 0x90B2D), false, true, sizeof(sect0));
		memcpy(func.sect0, sect0, sizeof(sect0));
		WriteJump((appBaseAddr + 0x90B28), func.addr);
		WriteCall((func.sect0 + 0xF), (appBaseAddr + 0x1FAA90));
		/*
		dmc3.exe+90B28 - E8 639F1600 - call dmc3.exe+1FAA90
		dmc3.exe+90B2D - 48 8B D0    - mov rdx,rax
		*/
	}



















}






#endif
