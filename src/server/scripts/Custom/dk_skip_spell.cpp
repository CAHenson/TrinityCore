#include "ScriptPCH.h"
#include "Player.h"

enum DK_SPELLS
{
	ACH_DOM = 51721,
	DEA_GAT = 50977,
	ACH_DEA = 48779,
};
class dk_start_bypass : public SpellScriptLoader
{
public:
	dk_start_bypass() : SpellScriptLoader("dk_start_bypass") { }

	class dk_start_bypass_SpellScript : public SpellScript
	{
		PrepareSpellScript(dk_start_bypass_SpellScript);

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			//Player* player = GetCaster()->GetAffectingPlayer()->ToPlayer();
			Player* target = GetHitPlayer();
			if (target->getClass() == 6)
			{
				target->CastSpell(target, ACH_DOM, false);
				target->CastSpell(target, DEA_GAT, false);
				target->CastSpell(target, ACH_DEA, false);
			}
			else
				return;

		}

		SpellScript* GetSpellScript() const
		{
			return new dk_start_bypass_SpellScript();
		}

		void Register()
		{
			OnEffectHit += SpellEffectFn(dk_start_bypass_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new dk_start_bypass_SpellScript();
	}

};
// this function call creates script loader object for us - seek that function at the end of the script file you're adding to
// if there's no such function see http://collab.kpsn.org/display/tc/How-to_CustomScript
void AddSC_dk_skip_scripts()
{
	new dk_start_bypass();
}