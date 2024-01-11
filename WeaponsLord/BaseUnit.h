#pragma once
#ifndef BASEUNIT_H
#define BASEUNIT_H

class BaseUnit {
public:
	BaseUnit(int health, int damage);
	virtual ~BaseUnit() = default;

	virtual void TakeDamage(int amount);
	virtual void PerformAttack(BaseUnit& target) = 0;
	virtual void UseSpecialAbility(BaseUnit& target) = 0;
	virtual void DisplayStatus() const;
	bool IsAlive() const;
	int GetDamage() const { return damage; }
	void SetDamage(int newDamage) { damage = newDamage; }
	bool IsStunned() const;
	void Stun();
	void EndTurn();

private:
	int health;
	int damage;
	bool stunned;
};

#endif 