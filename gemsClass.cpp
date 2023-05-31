#pragma once

#include "gemsClass.h"
Sn_StandardGem::Sn_StandardGem()
{
}

Sn_StandardGem::Sn_StandardGem(double xLoc, double yLoc, double size, const Sn_ColorIdentifier& col)
{
	m_xLoc = xLoc;
	m_yLoc = yLoc;

	m_size = size;
	m_color = col;
}

Sn_BonusAttribute Sn_StandardGem::getBonusAttribute()
{
	return Sn_BonusAttribute::nobonus;
}

void Sn_StandardGem::draw(const std::map<Sn_ColorIdentifier, Sn_RGBColor>& colorMap)
{
	glBegin(GL_POLYGON);
	Sn_RGBColor col = colorMap.at(m_color);
	glColor3f(double(col.redRGB) / 255.0, double(col.greenRGB) / 255.0, double(col.blueRGB) / 255.0);
	glVertex2f(m_xLoc, m_yLoc);
	glVertex2f(m_xLoc, m_yLoc + m_size);
	glVertex2f(m_xLoc + m_size, m_yLoc + m_size);
	glVertex2f(m_xLoc + m_size, m_yLoc);
	glEnd();
}

Sn_ColorIdentifier Sn_StandardGem::getColor()
{
	return m_color;
}

bool Sn_StandardGem::isScheduledForDeletion()
{
	return m_scheduledForDeletion;
}

void Sn_StandardGem::setScheduledForDeletion(bool deletion)
{
	m_scheduledForDeletion = deletion;
}

void Sn_StandardGem::setNewCoords(double xNew, double yNew)
{
	m_xLoc = xNew;
	m_yLoc = yNew;
}

void Sn_StandardGem::swapAttributes(Sn_StandardGem* other)
{
	if (other == NULL)
		return;

	auto tempXLoc = m_xLoc;
	auto tempYLoc = m_yLoc;

	m_xLoc = other->m_xLoc;
	m_yLoc = other->m_yLoc;

	other->m_xLoc = tempXLoc;
	other->m_yLoc = tempYLoc;
}

void Sn_StandardGem::setColor(const Sn_ColorIdentifier& newCol)
{
	m_color = newCol;
}

Sn_BonusGem::Sn_BonusGem(double xLoc, double yLoc, double size, const Sn_ColorIdentifier& col, const Sn_BonusAttribute& bonus)
{
	m_xLoc = xLoc;
	m_yLoc = yLoc;

	m_size = size;
	m_color = col;

	m_bonus = bonus;
}

Sn_BonusAttribute Sn_BonusGem::getBonusAttribute()
{
	return m_bonus;
}

void Sn_BonusGem::draw(const std::map<Sn_ColorIdentifier, Sn_RGBColor>& colorMap)
{
	glBegin(GL_POLYGON);
	Sn_RGBColor col = colorMap.at(m_color);
	glColor3f(double(col.redRGB) / 255.0, double(col.greenRGB) / 255.0, double(col.blueRGB) / 255.0);
	//glColor3f(0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glVertex2f(m_xLoc, m_yLoc);
	glVertex2f(m_xLoc, m_yLoc + m_size);
	glVertex2f(m_xLoc + m_size, m_yLoc + m_size);
	glVertex2f(m_xLoc + m_size, m_yLoc);
	glEnd();

	if (m_bonus == Sn_BonusAttribute::explosive)
	{
		glBegin(GL_POLYGON);
		glColor3f(255, 255, 255);
		glVertex2f(m_xLoc + m_size / 3.0, m_yLoc + m_size / 3.0);
		glVertex2f(m_xLoc + m_size / 3.0, m_yLoc + 2.0 * m_size / 3.0);
		glVertex2f(m_xLoc + 2.0 * m_size / 3.0, m_yLoc + 2.0 * m_size / 3.0);
		glVertex2f(m_xLoc + 2.0 * m_size / 3.0, m_yLoc + m_size / 3.0);
		glEnd();
	}
	else if (m_bonus == Sn_BonusAttribute::recolor)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(255, 255, 255);
		glVertex2f(m_xLoc + m_size / 2.0, m_yLoc + 2 * m_size / 3.0);
		glVertex2f(m_xLoc + m_size / 3.0, m_yLoc + m_size / 3.0);
		glVertex2f(m_xLoc + 2.0 * m_size / 3.0, m_yLoc + m_size / 3.0);
		glEnd();
	}
}