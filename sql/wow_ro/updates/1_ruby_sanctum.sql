-- Script Texts
REPLACE INTO script_texts (`entry`, `content_default`, `npc_entry`, `content_loc3`, `sound`, `type`, `language`) VALUES
('-1752008', '', '0', 'Help I''m caught in that tree! Help me!', '17490', '1', '7'),	 	
('-1752009', '', '0', 'Thank you', '17491', '1', '7'),	 	
('-1752010', '', '0', 'We believed the Sanctum is well appreciated but this type of attack we were not prepared ...', '17492', '0', '7'),	 	
('-1752011', '', '0', 'The Black Dragonkin appeared from nowhere and attacked us to respond before we could ...', '17493', '0', '7'), 	
('-1752012', '', '0', 'We had no chance ... While my brothers died, I could retire here and the entrance block.', '17494', '0', '7'), 	
('-1752013', '', '0', 'They slaughtered us with cold efficiency ... But their wares goal seemed to be the eggs which are located in the Sanctum.', '17495', '0', '7'),	
('-1752014', '', '0', 'The commander of ground troops is a cruel beast called Zarithrian. But I fear greater powers are at work ...', '17496', '0', '7'),	
('-1752015', '', '0', 'I saw in their attack shortly their true leader ... a terrible twilight adult dragon.', '17497', '0', '7'),	
('-1752016', '', '0', 'I know their exact plans but I know one thing: They may not be successful!', '17498', '0', '7'),

( -1752001, "Ah, the entertainment has arrived.", 0, "Ahh...Die Unterhaltung ist eingetroffen!", 17520, 1, 7),
( -1752002, "Baltharus leaves nobody alive!", 0, "Baltharus lasst niemanden am Leben!", 17521, 1, 7),
( -1752003, "This world has enough heroes.", 0, "Diese Welt hat genug Helden!", 17522, 1, 7),
( -1752004, "I..didn''t saw...that coming...", 0, "Das...habe ich...nicht..kommen sehen...", 17523, 1, 7),
( -1752005, "Twice the pain and half the fun.", 0, "Doppelter Schmerz, Halb so viel Spa?!", 17524, 1, 7),
( -1752006, "", 0, "Eure Macht schwindet, Uralte! Balt folgt ihr euren Freunden!", 17525, 1, 7),

( -1752017, "Alexstrasza has chosen capable allies... A pity that I must END YOU!", 0, "Alextrasza hat fahige Verbundete... Zu Schade, dass es hier mit euch ENDET!", 17512, 1, 7),
( -1752018, "You thought you stood a chance?", 0, "Ihr dachtet ihr konntet bestehen?", 17513, 1, 7),
( -1752019, "It''s for the best.", 0, "Es ist zu eurem Besten.", 17514, 1, 7),
( -1752020, "HALION! I...", 0, "HALION! Ich...", 17515, 1, 7),
( -1752021, "Turn them to ashes, minions!", 0, "Aschert sie ein, Lakeien!", 17516, 1, 7),

( -1752022, "You will sssuffer for this intrusion!", 0, "Fur dieses Eindringen werdet ihr leiden!", 17528, 1, 7),
( -1752023, "As it should be...", 0, "Wie es sich gehort...", 17529, 1, 7),
( -1752024, "Halion will be pleased", 0, "Halion wird erfreut sein...", 17530, 1, 7),
( -1752025, "Hhrr...Grr..", 0, "HHrr...Grr..", 17531, 1, 7),
( -1752026, "Burn in the master's flame!", 0, "Brennt in der Flamme des Meisters!", 17532, 1, 7),

(-1752027, 'Insects! You''re too late. The Ruby Sanctum is lost.',null,null,null,null,null,null,null,null,17499,1,0,0,'');
(-1752028, 'Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!',null,null,null,null,null,null,null,null,17500,1,0,0,'');
(-1752029, 'Another hero falls.',null,null,null,null,null,null,null,null,17501,1,0,0,'');
(-1752030, 'Hahahahaha.',null,null,null,null,null,null,null,null,17502,1,0,0,'');
(-1752031, 'Relish this victory, mortals, for it will be your last! This world will burn with the master''s return!',null,null,null,null,null,null,null,null,17503,1,0,0,'');
(-1752032, 'Not good enough.',null,null,null,null,null,null,null,null,17504,1,0,0,'');
(-1752033, 'The heavens burn!',null,null,null,null,null,null,null,null,17505,1,0,0,'');
(-1752034, 'Beware the shadow!',null,null,null,null,null,null,null,null,17506,1,0,0,'');
(-1752035, 'You will find only suffering within the realm of twilight! Enter if you dare!',null,null,null,null,null,null,null,null,17507,1,0,0,'');
(-1752036, 'I am the light and the darkness! Cower, mortals, before the herald of Deathwing!',null,null,null,null,null,null,null,null,17508,1,0,0,'');

-- Scriptnames
UPDATE `instance_template` SET `script`='instance_ruby_sanctum' WHERE (`map`='724');
UPDATE `creature_template` SET `ScriptName` = 'boss_baltharus' WHERE `entry` = '39751';
UPDATE `creature_template` SET `ScriptName` = 'boss_baltharus_clone' WHERE `entry` = '39899';
UPDATE `creature_template` SET `ScriptName` = 'npc_xerestrasza' WHERE `entry` = '40429';
UPDATE `creature_template` SET `ScriptName` = 'boss_zarithrian' WHERE `entry` = '39746';
UPDATE `creature_template` SET `ScriptName` = 'boss_ragefire' WHERE `entry` = '39747';
UPDATE `creature_template` SET `ScriptName` = 'boss_halion' WHERE `entry`= '39863';
UPDATE `creature_template` SET `ScriptName` = 'boss_twilight_halion' WHERE `entry` = '40142';
UPDATE `creature_template` SET `ScriptName` = 'npc_onyx_flamecaller' WHERE `entry` = '39814';
UPDATE `gameobject_template` SET `ScriptName` = 'go_firefield' WHERE `entry` = '203005';