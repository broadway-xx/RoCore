ALTER TABLE db_version CHANGE COLUMN required_187_world_halls_of_reflection required_205_world_access_requirement bit;

TRUNCATE `access_requirement`;
INSERT INTO `access_requirement` VALUES
(33,0,14,0,0,0,0,0,0, NULL, 'Shadowfang Keep Entrance'),
(34,0,15,0,0,0,0,0,0, NULL, 'Stormwind Stockades Entrance'),
(36,0,10,0,0,0,0,0,0, NULL, 'DeadMines Entrance'),
(43,0,10,0,0,0,0,0,0, NULL, 'The Barrens - Wailing Caverns'),
(47,0,17,0,0,0,0,0,0, NULL, 'Razorfen Kraul Entrance'),
(48,0,19,0,0,0,0,0,0, NULL, 'Blackphantom Deeps Entrance'),
(70,0,30,0,0,0,0,0,0, NULL, 'Uldaman Entrance'),
(90,0,15,0,0,0,0,0,0, NULL, 'Gnomeregan Entrance'),
(109,0,35,0,0,0,0,0,0, NULL, 'Altar of Atal''Hakkar Entrance'),
(129,0,25,0,0,0,0,0,0, NULL, 'Razorfen Downs Entrance'),
(189,0,20,0,0,0,0,0,0, NULL, 'Scarlet Monastery - Graveyard (Entrance)'),
(209,0,35,0,0,0,0,0,0, NULL, 'Zul''Farrak Entrance'),
(229,0,45,0,0,0,0,0,0, NULL, 'Blackrock Spire - Searing Gorge Instance (Inside)'),
(230,0,40,0,0,0,0,0,0, NULL, 'Blackrock Mountain - Searing Gorge Instance?'),
(249,0,80,0,0,0,0,0,0, NULL, 'Onyxia''s Lair Entrance'),
(249,1,80,0,0,0,0,0,0, NULL, 'Onyxia''s Lair Entrance'),
(269,0,66,0,0,0,10285,10285,0, 'You must complete the quest \"Return to Andormu\" before entering the Black Morass.', 'Caverns Of Time, Black Morass (Entrance)'),
(269,1,70,0,30635,0,10285,10285,0, 'You must complete the quest \"Return to Andormu\" and be level 70 before entering the Heroic difficulty of the Black Morass.', 'Caverns Of Time, Black Morass (Entrance)'),
(289,0,45,0,0,0,0,0,0, NULL, 'Scholomance Entrance'),
(309,0,50,0,0,0,0,0,0, NULL, 'Zul''Gurub Entrance '),
(329,0,45,0,0,0,0,0,0, NULL, 'Stratholme - Eastern Plaguelands Instance'),
(349,0,30,0,0,0,0,0,0, NULL, 'Maraudon'),
(389,0,8,0,0,0,0,0,0, NULL, 'Ragefire Chasm - Ogrimmar Instance'),
(409,0,50,0,0,0,0,0,0, NULL, 'The Molten Bridge'),
(429,0,45,0,0,0,0,0,0, NULL, 'Dire Maul'),
(469,0,60,0,0,0,0,0,0, NULL, 'Blackwing Lair - Blackrock Mountain - Eastern Kingdoms'),
(509,0,50,0,0,0,0,0,0, NULL, 'Ruins Of Ahn\'Qiraj (Outside)'),
(531,0,50,0,0,0,0,0,0, NULL, 'Ahn\'Qiraj Temple (Outside)'),
(532,0,68,0,0,0,0,0,0, NULL, 'Karazhan, Main (Entrance)'),
(533,0,80,0,0,0,0,0,0, NULL, 'Naxxramas'),
(533,1,80,0,0,0,0,0,0, NULL, 'Naxxramas'),
(534,0,70,0,0,0,0,0,0, NULL, 'Battle Of Mount Hyjal, Alliance Base (Entrance)'),
(540,0,55,0,0,0,0,0,0, NULL, 'The Shattered Halls (Entrance)'),
(540,1,70,0,30637,30622,0,0,0, NULL, 'The Shattered Halls (Entrance)'),
(542,0,55,0,0,0,0,0,0, NULL, 'The Blood Furnace (Entrance)'),
(542,1,70,0,30637,30622,0,0,0, NULL, 'The Blood Furnace (Entrance)'),
(543,0,55,0,0,0,0,0,0, NULL, 'Hellfire Ramparts (Entrance)'),
(543,1,70,0,30637,30622,0,0,0, NULL, 'Hellfire Ramparts (Entrance)'),
(544,0,65,0,0,0,0,0,0, NULL, 'Magtheridon''s Lair (Entrance)'),
(545,0,55,0,0,0,0,0,0, NULL, 'The Steamvault (Entrance)'),
(545,1,70,0,30623,0,0,0,0, NULL, 'The Steamvault (Entrance)'),
(546,0,55,0,0,0,0,0,0, NULL, 'The Underbog (Entrance)'),
(546,1,70,0,30623,0,0,0,0, NULL, 'The Underbog (Entrance)'),
(547,0,55,0,0,0,0,0,0, NULL, 'The Slave Pens (Entrance)'),
(547,1,70,0,30623,0,0,0,0, NULL, 'The Slave Pens (Entrance)'),
(548,0,68,0,0,0,0,0,0, NULL, 'Serpentshrine Cavern (Entrance)'),
(550,0,70,0,0,0,0,0,0, NULL, 'The Eye (Entrance)'),
(552,0,68,0,0,0,0,0,0, NULL, 'The Arcatraz (Entrance)'),
(552,1,70,0,30634,0,0,0,0, NULL, 'The Arcatraz (Entrance)'),
(553,0,68,0,0,0,0,0,0, NULL, 'The Botanica (Entrance)'),
(553,1,70,0,30634,0,0,0,0, NULL, 'The Botanica (Entrance)'),
(554,0,68,0,0,0,0,0,0, NULL, 'The Mechanar (Entrance)'),
(554,1,70,0,30634,0,0,0,0, NULL, 'The Mechanar (Entrance)'),
(555,0,65,0,0,0,0,0,0, NULL, 'Shadow Labyrinth (Entrance)'),
(555,1,70,0,30633,0,0,0,0, NULL, 'Shadow Labyrinth (Entrance)'),
(556,0,55,0,0,0,0,0,0, NULL, 'Sethekk Halls (Entrance)'),
(556,1,70,0,30633,0,0,0,0, NULL, 'Sethekk Halls (Entrance)'),
(557,0,55,0,0,0,0,0,0, NULL, 'Mana Tombs (Entrance)'),
(557,1,70,0,30633,0,0,0,0, NULL, 'Mana Tombs (Entrance)'),
(558,0,55,0,0,0,0,0,0, NULL, 'Auchenai Crypts (Entrance)'),
(558,1,70,0,30633,0,0,0,0, NULL, 'Auchenai Crypts (Entrance)'),
(560,0,66,0,0,0,0,0,0, NULL, 'Caverns Of Time, Old Hillsbrad Foothills (Entrance)'),
(560,1,70,0,30635,0,0,0,0, NULL, 'Caverns Of Time, Old Hillsbrad Foothills (Entrance)'),
(564,0,70,0,0,0,0,0,0, NULL, 'Black Temple (Entrance)'),
(565,0,70,0,0,0,0,0,0, NULL, 'Gruul''s Lair (Entrance)'),
(568,0,70,0,0,0,0,0,0, NULL, 'Zul''Aman (Entrance)'),
(574,0,65,0,0,0,0,0,0, NULL, 'Utgarde Keep (entrance)'),
(574,1,80,0,0,0,0,0,0, NULL, 'Utgarde Keep (entrance)'),
(575,0,75,0,0,0,0,0,0, NULL, 'Utgarde Pinnacle (entrance)'),
(575,1,80,0,0,0,0,0,0, NULL, 'Utgarde Pinnacle (entrance)'),
(576,0,66,0,0,0,0,0,0, NULL, 'The Nexus (entrance)'),
(576,1,80,0,0,0,0,0,0, NULL, 'The Nexus (entrance)'),
(578,0,75,0,0,0,0,0,0, NULL, 'The Oculus (entrance)'),
(578,1,80,0,0,0,0,0,0, NULL, 'The Oculus (entrance)'),
(580,0,70,0,0,0,0,0,0, NULL, 'Sunwell Plateau (Entrance)'),
(585,0,65,0,0,0,0,0,0, NULL, 'Magisters\' Terrace (Entrance)'),
(585,1,70,0,0,0,11492,11492,0, NULL, 'Magisters\' Terrace (Entrance)'),
(595,0,75,0,0,0,0,0,0, NULL, 'Culling of Stratholme (entrance)'),
(595,1,80,0,0,0,0,0,0, NULL, 'Culling of Stratholme (entrance)'),
(599,0,72,0,0,0,0,0,0, NULL, 'Ulduar, Halls of Stone (entrance)'),
(599,1,80,0,0,0,0,0,0, NULL, 'Ulduar, Halls of Stone (entrance)'),
(600,0,69,0,0,0,0,0,0, NULL, 'Drak''Tharon Keep (entrance)'),
(600,1,80,0,0,0,0,0,0, NULL, 'Drak''Tharon Keep (entrance)'),
(601,0,67,0,0,0,0,0,0, NULL, 'Azjol-Nerub (entrance)'),
(601,1,80,0,0,0,0,0,0, NULL, 'Azjol-Nerub (entrance)'),
(602,0,75,0,0,0,0,0,0, NULL, 'Ulduar, Halls of Lightning (entrance)'),
(602,1,80,0,0,0,0,0,0, NULL, 'Ulduar, Halls of Lightning (entrance)'),
(603,0,80,0,0,0,0,0,0, NULL, 'Ulduar Raid entrance'),
(603,1,80,0,0,0,0,0,0, NULL, 'Ulduar Raid entrance'),
(604,0,71,0,0,0,0,0,0, NULL, 'Gundrak (entrance north)'),
(604,1,80,0,0,0,0,0,0, NULL, 'Gundrak (entrance north)'),
(608,0,70,0,0,0,0,0,0, NULL, 'Violet Hold (entrance)'),
(608,1,80,0,0,0,0,0,0, NULL, 'Violet Hold (entrance)'),
(615,0,80,0,0,0,0,0,0, NULL, 'Chamber of Aspects, Obsidian Sanctum (entrance)'),
(615,1,80,0,0,0,0,0,0, NULL, 'Chamber of Aspects, Obsidian Sanctum (entrance)'),
(616,0,80,0,0,0,0,0,0, NULL, 'The Eye of Eternity (entrance)'),
(616,1,80,0,0,0,0,0,0, NULL, 'The Eye of Eternity (entrance)'),
(619,0,68,0,0,0,0,0,0, NULL, 'Ahn''Kahet (entrance)'),
(619,1,80,0,0,0,0,0,0, NULL, 'Ahn''Kahet (entrance)'),
(624,0,80,0,0,0,0,0,0, NULL, 'Vault of Archavon (Entrance)'),
(624,1,80,0,0,0,0,0,0, NULL, 'Vault of Archavon (Entrance)'),
(631,0,80,0,0,0,0,0,0, NULL, 'IceCrown Citadel (Entrance)'),
(631,1,80,0,0,0,0,0,0, NULL, 'IceCrown Citadel (Entrance)'),
(631,2,80,0,0,0,0,0,4530, NULL, 'IceCrown Citadel (Entrance)'),
(631,3,80,0,0,0,0,0,4597, NULL, 'IceCrown Citadel (Entrance)'),
(632,0,80,0,0,0,0,0,0, NULL, 'Forge of Souls (Entrance)'),
(632,1,80,0,0,0,0,0,0, NULL, 'Forge of Souls (Entrance)'),
(649,0,80,0,0,0,0,0,0, NULL, 'Trial of the Crusader'),
(649,1,80,0,0,0,0,0,0, NULL, 'Trial of the Crusader'),
(649,2,80,0,0,0,0,0,0, NULL, 'Trial of the Crusader'),
(649,3,80,0,0,0,0,0,0, NULL, 'Trial of the Crusader'),
(650,0,75,0,0,0,0,0,0, NULL, 'Trial of the Champion'),
(650,1,80,0,0,0,0,0,0, NULL, 'Trial of the Champion'),
(658,0,80,0,0,0,24499,24511,0, NULL, 'Pit of Saron (Entrance)'),
(658,1,80,0,0,0,24499,24511,0, NULL, 'Pit of Saron (Entrance)'),
(668,0,80,0,0,0,24710,24712,0, NULL, 'Halls of Reflection (Entrance)'),
(668,1,80,0,0,0,24710,24712,0, NULL, 'Halls of Reflection (Entrance)'),
(724,0,80,0,0,0,0,0,0, NULL, 'The Ruby Sanctum (Entrance)'),
(724,1,80,0,0,0,0,0,0, NULL, 'The Ruby Sanctum (Entrance)'),
(724,2,80,0,0,0,0,0,0, NULL, 'The Ruby Sanctum (Entrance)'),
(724,3,80,0,0,0,0,0,0, NULL, 'The Ruby Sanctum (Entrance)');