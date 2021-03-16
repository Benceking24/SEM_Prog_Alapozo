# SEM Digitális rendszer alapok és beágyazott C programozás

__Előadás felvétel:__ https://youtu.be/7lFY-UZmM6I

__Előadás jegyzet (fájlok közt feltölve):__ https://github.com/Benceking24/SEM_Prog_Alapozo/blob/master/El%C5%91ad%C3%A1s%20jegyzet.pdf

__Fejlesztő környzete telepítése:__
* Arduino IDE telepítése (https://www.arduino.cc/en/software), opcionálisan fejlesztőlap leírásának és könyvtárak telepítése
* VsCode telepítése (https://code.visualstudio.com/download)
* VsCode pluginok telepítés:
	* C/C++ plguin (Microsoft)
	* Arduino (Microsoft)
* VsCode beállításának módosítása (szerkesztés fájlként - settings.json):
```{"arduino.path": "C:\\Program Files (x86)\\Arduino", "arduino.additionalUrls": "", "arduino.logLevel": "verbose", "arduino.enableUSBDetection": true, "C_Cpp.intelliSenseEngine": "Tag Parser"}```
* Arduino plugin beállítás: Settings -> Extensions -> Arduino config...: Arduino Log Level: Verbose

__Új projekt létrehozás:__
* Mappa létrehozása
* Fájl létrehozás ".ino" kiterjesztéssel
* Projekt beállítása: ("CTRL + P")
	* Borad type
	* Buad rate
	* Serial port
*Generált propreties json kiegészítése:
```
"configurations": [
  {
	"includePath": [
	...,
	        "${workspaceFolder}/**",
                "C:/Program Files (x86)/Arduino/**"
	],
    ...,

    "browse": {
      "path": [
                "${workspaceFolder}",
      		"C:/Program Files (x86)/Arduino/**"	
      ],
      "limitSymbolsToIncludedHeaders": true
    }
  }
]
```
