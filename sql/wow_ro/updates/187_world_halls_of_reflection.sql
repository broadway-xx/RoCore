ALTER TABLE db_version CHANGE COLUMN required_183_world_wintergrasp required_187_world_halls_of_reflection bit;

-- Cleanup first
UPDATE `creature_template` SET `Scriptname`=' ' WHERE `entry` IN (38112,38113,37221,37223,38175,38172,38567,38177,38173,38176);
UPDATE `instance_template` SET `script`='instance_halls_of_reflection' WHERE (`map`='668');

UPDATE `creature_template` SET `ScriptName`='arthas' WHERE (`entry`='37226'); 
UPDATE `creature_template` SET `ScriptName`='uther' WHERE (`entry`='37225'); 
UPDATE `creature_template` SET `ScriptName`='sylvanas' WHERE (`entry`='37223');
UPDATE `creature_template` SET `ScriptName`='boss_falric' WHERE (`entry`='38112'); 
UPDATE `creature_template` SET `ScriptName`='ghoul' WHERE (`entry`='36940');
UPDATE `creature_template` SET `ScriptName`='doctor' WHERE (`entry`='36941');
UPDATE `creature_template` SET `ScriptName`='lumbi' WHERE (`entry`='37069'); 
UPDATE `creature_template` SET `ScriptName`='boss_marwyn' WHERE (`entry`='38113'); 

INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `faction_A`, `faction_H`, `rank`, `unit_class`, `type`, `type_flags`, `Health_mod`, `Mana_mod`, `movementId`, `ScriptName`, `WDBVerified`) 
VALUES ('37228', '30721', 'The Lich King', '35', '35', '3', '1', '6', '36', '2000', '500', '151', 'arthas2', '11403');

DELETE FROM `gameobject` WHERE `id`=201911;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(201911, 668, 1, 1, 5517.24, 2031.8, 731.932, 4.53518, 0, 0, 0.766905, -0.64176, 300, 0, 1),
(201911, 668, 1, 1, 5533.66, 2073.37, 730.984, 4.30898, 0, 0, 0.834433, -0.55111, 300, 0, 1),
(201911, 668, 1, 1, 5444.72, 1893.8, 749.007, 4.04508, 0, 0, 0.899686, -0.436537, 300, 0, 1),
(201911, 668, 1, 1, 5304.27, 1734.61, 775.811, 4.0011, 0, 0, 0.909068, -0.416648, 300, 0, 1),
(201911, 668, 1, 1, 5553.35, 2066.69, 733.295, 4.50297, 0, 0, 0.777139, -0.62933, 300, 0, 1),
(201911, 668, 1, 1, 5535.42, 2026.25, 732.39, 4.25396, 0, 0, 0.849276, -0.527949, 300, 0, 1),
(201911, 668, 1, 1, 5462, 1889.82, 752.294, 4.22254, 0, 0, 0.857464, -0.514544, 300, 0, 1);