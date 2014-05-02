/*
 * Copyright 2014 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARX_GAME_MAGIC_SPELLS_SPELLSLVL08_H
#define ARX_GAME_MAGIC_SPELLS_SPELLSLVL08_H

#include "game/magic/Spell.h"

class InvisibilitySpell : public SpellBase {
public:
	void Launch(long i, long duration);
	void End(long i);
	void Update(size_t i);
};

class ManaDrainSpell : public SpellBase {
public:
	void Launch(long duration);
	void End();
	void Update(float timeDelta);
};

class ExplosionSpell : public SpellBase {
public:
	void Launch();
	void Update();
};

class EnchantWeaponSpell : public SpellBase {
public:
	void Launch(bool & notifyAll);
	void Update(float timeDelta);
};

class LifeDrainSpell : public SpellBase {
public:
	void Launch(long duration);
	void End();
	void Update(float timeDelta);
};

#endif // ARX_GAME_MAGIC_SPELLS_SPELLSLVL08_H