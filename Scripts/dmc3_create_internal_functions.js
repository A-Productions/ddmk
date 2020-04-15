var c = "";
var fs = require("fs");

var items =
[
	[ 0x897B0 , "void"   , "byte8 * dest"                                                             , ""                            , "" ],
	[ 0x89450 , "void"   , "byte8 * dest"                                                             , ""                            , "" ],
	[ 0x89270 , "void"   , "byte8 * dest"                                                             , ""                            , "" ],
	[ 0x8B470 , "void"   , "byte8 * dest, uint32 flag"                                                , ""                            , "" ],
	[ 0x89960 , "void"   , "byte8 * dest, byte8 * modelFile, byte8 * textureFile"                     , ""                            , "" ],
	[ 0x89DE0 , "byte8 *", "byte8 * dest"                                                             , "0, true, false"              , "" ],
	[ 0x8BC60 , "void"   , "byte8 * dest, byte8 * addr, byte8 * shadowFile"                           , ""                            , "" ],
	[ 0x305D80, "void"   , "byte8 * dest"                                                             , ""                            , "" ],
	[ 0x8A000 , "void"   , "byte8 * dest, byte8 * motionFile, byte8 * addr"                           , ""                            , "" ],
	[ 0x2C9F40, "uint32" , "byte8 * physicsFile"                                                      , "0, true, false"              , "" ],
	[ 0x2CA1D0, "void"   , "byte8 * dest, byte8 * addr, byte8 * physicsFile, uint32 index"            , ""                            , "" ],
	[ 0x2CA2F0, "void"   , "byte8 * dest, byte8 * addr, byte8 *, MODEL_METADATA * modelData, uint32 count", "0, true, true, 0, 0, 0, 0, 1", "" ],
	[ 0x1EF040, "void"   , "byte8 * baseAddr, uint32 index"                                           , ""                            , "" ],
	//[ 0x1F92C0, "void"   , "byte8 * dest, byte32 flag"                                                , ""                            , "" ],
	//[ 0x1F97F0, "void"   , "byte8 * dest, byte32 flag"                                                , ""                            , "" ],
	[ 0x2EE3D0, "void"   , "byte8 * dest"                                                             , ""                            , "" ],
	[ 0x1FAF40, "void"   , "byte8 * baseAddr"                                                         , ""                            , "" ],
	[ 0x1EEF80, "void"   , "byte8 * baseAddr"                                                         , ""                            , "" ],
	[ 0x2EE060, "bool"   , "byte8 * dest, uint32 size"                                                , ""                            , "" ],
	[ 0x1DE820, "byte8 *", "uint32 character, uint32 id, bool isClone"                                , "0, true, false"              , "Create Actor" ],
	[ 0x1BB390, "void"   , "byte8 ** pool, uint32 actor"                                              , ""                            , "" ],
	[ 0x217B90, "void"   , "byte8 * baseAddr, byte8 * sessionData"                                    , ""                            , "" ],
	[ 0x223CB0, "void"   , "byte8 * baseAddr, byte8 * sessionData"                                    , ""                            , "" ],
	[ 0x1DFC20, "void"   , "byte8 * baseAddr"                                                         , ""                            , "" ],
	
	// @Todo: Get all register weapon functions.
	
	[ 0x2310B0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22EC90, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x227870, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22A1E0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x228CF0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22B0C0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x2306B0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22C4A0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x2300A0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22BA30, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22D960, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x2298E0, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	[ 0x22CF00, "byte8 *", "byte8 * baseAddr, uint32 id"                                              , "0, true, false"              , "" ],
	
	[ 0x23E560, "void"   , "byte8 * eventData, uint32 position"                                       , ""                            , "" ],
	
	[ 0x280120, "void"   , "byte8 * baseAddr, uint32 side, uint32 index"                              , ""                            , "Weapon Switch Animation Dante"       ],
	
	
	
	
	[ 0x280160, "void"   , "byte8 *, uint32 group, uint32 index, uint32 motion"                              , ""                            , "Weapon Switch Animation Vergil"      ],
	
	
	
	[ 0x1EB0E0, "void"   , "ACTOR_DATA & actorData, uint32 index"                                     , ""                            , "Call after Weapon Switch Animation." ],
	
	
	
	[ 0x1F92C0, "void"   , "ACTOR_DATA & actorData, uint32 phase"                                     , ""                            , "Queue devil model update."           ], // @Research: Works like bool, but has size of uint32.
	[ 0x1F97F0, "void"   , "ACTOR_DATA & actorData, bool playMotion"                                  , ""                            , "Update devil model and play motion." ],
	
	
	
	
	
	//dmc3.exe+8AC80
	
	[ 0x8AC80, "void"   , "MODEL_DATA & modelData, uint32 bodyPart, byte8 * motionFile, uint32, bool", "0, true, true, 0, 0, 0, 0, 1"                            , "Play Motion" ],
	
	
	
	
	
	/*
dmc3.exe+5A432 - 4C 8D 04 02           - lea r8,[rdx+rax] { add off
 }
dmc3.exe+5A436 - 48 8B 4B 70           - mov rcx,[rbx+70]
dmc3.exe+5A43A - 41 8B D2              - mov edx,r10d
dmc3.exe+5A43D - 44 0FB6 CD            - movzx r9d,bpl
dmc3.exe+5A441 - 40 88 74 24 20        - mov [rsp+20],sil
dmc3.exe+5A446 - 48 8B 01              - mov rax,[rcx]
dmc3.exe+5A449 - FF 50 08              - call qword ptr [rax+08] { dmc3.exe+8AF20
 }
	*/
	
	
	
	
	
	
	
	
	
	
	
	/*
	
	
dmc3.exe+1EAA0E - BA 01000000           - mov edx,00000001 { 1 }
dmc3.exe+1EAA13 - 48 8B CF              - mov rcx,rdi
dmc3.exe+1EAA16 - E8 A5E80000           - call dmc3.exe+1F92C0 { queue
 }
dmc3.exe+1EAA1B - B2 01                 - mov dl,01 { 1 }
dmc3.exe+1EAA1D - 48 8B CF              - mov rcx,rdi
dmc3.exe+1EAA20 - E8 CBED0000           - call dmc3.exe+1F97F0 { update
 }

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	dmc3.exe+1EA9E7 - E8 F4060000           - call dmc3.exe+1EB0E0
dmc3.exe+1EA9EC - 80 BF 9B3E0000 01     - cmp byte ptr [rdi+00003E9B],01 { 1 }
dmc3.exe+1EA9F3 - 74 19                 - je dmc3.exe+1EAA0E
dmc3.exe+1EA9F5 - 8B 87 943E0000        - mov eax,[rdi+00003E94]
dmc3.exe+1EA9FB - 83 F8 01              - cmp eax,01 { 1 }

	

dmc3.exe+280120
dmc3.exe+280160



	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
];

for (var index = 0; index < items.length; index++)
{
	var off                = items[index][0];
	var returnType         = items[index][1];
	var args               = items[index][2];
	var createFunctionArgs = items[index][3];
	var hint               = items[index][4];
	
	var offStr = off.toString(16).toUpperCase();
	
	c += "typedef " + returnType + "(__fastcall * func_" + offStr + "_t)(" + args + ");";
	if (hint != "")
	{
		c += " // " + hint;
	}
	c += "\r\n";
}

c += "\r\n";

for (var index = 0; index < items.length; index++)
{
	var off                = items[index][0];
	var returnType         = items[index][1];
	var args               = items[index][2];
	var createFunctionArgs = items[index][3];
	var hint               = items[index][4];
	
	var offStr = off.toString(16).toUpperCase();
	
	c += "extern func_" + offStr + "_t func_" + offStr + ";\r\n";
}

c += "\r\n";

for (var index = 0; index < items.length; index++)
{
	var off                = items[index][0];
	var returnType         = items[index][1];
	var args               = items[index][2];
	var createFunctionArgs = items[index][3];
	var hint               = items[index][4];
	
	var offStr = off.toString(16).toUpperCase();
	
	c += "func_" + offStr + "_t func_" + offStr + " = 0;\r\n";
}

c += "\r\n";

for (var index = 0; index < items.length; index++)
{
	var off                = items[index][0];
	var returnType         = items[index][1];
	var args               = items[index][2];
	var createFunctionArgs = items[index][3];
	var hint               = items[index][4];
	
	var offStr = off.toString(16).toUpperCase();
	
	c += "{\r\n";
	c += "\tauto func = CreateFunction((appBaseAddr + 0x" + offStr + ")";
	if (createFunctionArgs != "")
	{
		c += ", " + createFunctionArgs;
	}
	c += ");\r\n";
	c += "\tfunc_" + offStr + " = (func_" + offStr + "_t)func.addr;\r\n";
	c += "}\r\n";
}

fs.writeFileSync("internal.cpp", c);
