#include "Orc.h"
#include "Knight.h"
#include <iostream>
using namespace std;

//mt19937 Knight::gen(random_device{}());

Orc::Orc() : BaseUnit(60, 8), gen(random_device{}()), stunCoolDown(0) {}

void Orc::PerformAttack(BaseUnit& target) {
	if (TryStunAttack()) {
		UseSpecialAbility(target);
	}
	else {
		BaseUnit::PerformAttack(target);
	}

	if (stunCoolDown > 0) {
		--stunCoolDown;
	}
}

bool Orc::TryStunAttack() {
	//random_device rd;
	//mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);

	return stunCoolDown == 0 && dis(gen) < STUN_ATTACK_SUCCES_RATE;
}

void Orc::UseSpecialAbility(BaseUnit& target) {
	if (TryStunAttack()) {
		target.Stun();
		cout << "Le chevalier est étourdi et ne pourra pas agir au prochain tour !" << endl;
		stunCoolDown = STUN_ATTACK_COOLDOWN;
	}
}

void Orc::DisplayStatus() const {
	BaseUnit::DisplayStatus();
}