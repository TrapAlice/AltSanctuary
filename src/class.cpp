#include "class.h"

std::string CLASS_INFO(Class c){
	switch(c){
		case Class::BARBARIAN:
			return "Regenerates 5%%%% of max HP each turn when health is below 50%%%%\nIncreased healing ability based on RAGE meter.\nGains 20 MP per Reposition.\nIncreased lifesteal from lifesteal abilities.\nGains additional attack power from points in VIT.\nHas chance for Whirlwind [2] to break GUARDING.\nUsing Cleave [1] will remove ENSNARE effects.";
		case Class::PALADIN:
			return "When MP is above 50%%%%, regenerates a small 5%%%% of current HP per turn.\nThis HP regeneration is doubled if ARCANE meter is maxed.\nGains 20 MP per reposition.\nGains additional damage from points in Wisdom.\nHas small chance to block enemy attacks.\nHas 50%%%% chance to remove a random status debuff when using Reckoning [W].\nIncreased health gain when casting Heal [4].";
		case Class::ASSASSIN:
			return "Bleeds enemy when their health drops below 50%%%%.\nHas small chance to Bleed enemies upon attack when RAGE meter is maxed.\nGains 25 MP per reposition.\nHas small chance to confuse enemies upon repositioning.\nIncreased chance to dodge enemy attack after repositioning.\nHas 50%%%% chance to restore MP when using Deadly Mark [W].\nUsing Heal [4] will DAZE enemies.";
		case Class::WIZARD:
			return "When MP is below 50%%%%, regenerate a small amount of MP per turn.\nChance to FREEZE when casting ULT. Fire deals bonus damage to frozen targets.\nGains 25 MP per Reposition.\nHas small chance to BURN enemy with Ignite [W].\nGains additional damage from points in Wisdom and Intelligence.\nHas small chance to SHOCK enemy with Electrocute [2].\nCasting Heal [4] will DAZE enemies.";
		case Class::DRUID:
			return "After casting ULT, MAX HP increases temporarily.\nWhen ULT is fully charged, regenerate a small amount of HP per turn.\nGains 20 MP per Reposition.\nGains additional damage from points in Intelligence.\nIncreased damage with Slash [1], scaling with length of battle.\nGains chance to MARK enemies with Rabid Lunge [2], up to three MARKS.\nCasting ULT consumes all MARKs for bonus DMG.";
		case Class::RANGER:
			return "When ULT is fully charged, dodge chance is increased threefold.\nGains 5 MP upon dodging and dazing enemies when SPIRIT meter is maxed.\nGains 25 MP per Reposition.\nSmall Chance to MARK when attacking. At 3rd MARK, enemy takes bonus damage.\nHas decent chance to CONFUSE enemies with Infused Bolt [W].\nUsing Guided Arrow [1] will interrupt CHARGING enemies.\nCasting Heal will DAZE enemies.";
	}
	return "Error";
}

