#include "ParticipantOfTheCompetitionInit.hpp"

ParticipantsOfTheCompetition::ParticipantsOfTheCompetition()
    : last_name("\0"), first_name("\0"), _category("\0"), _country("\0"), birth_year(), id_Participant(0)
{
}

ParticipantsOfTheCompetition::ParticipantsOfTheCompetition(const std::string& lastName, const std::string& firstName, const std::string& category, const std::string& country, const Date& birthYear, const unsigned short& idParticipant)
    :last_name(lastName), first_name(firstName), _category(category), _country(country), birth_year(birthYear), id_Participant(idParticipant)
{
}

ParticipantsOfTheCompetition::ParticipantsOfTheCompetition(const ParticipantsOfTheCompetition& participant) : last_name(participant.last_name), first_name(participant.first_name), _category(participant._category), _country(participant._country), birth_year(participant.birth_year), id_Participant(participant.id_Participant)
{
}


const ParticipantsOfTheCompetition& ParticipantsOfTheCompetition::operator=(const ParticipantsOfTheCompetition& Participant)
{
    first_name = Participant.first_name;
    last_name = Participant.last_name;
    _category = Participant._category;
    _country = Participant._country;
    birth_year = Participant.birth_year;
    id_Participant = Participant.id_Participant;

    return *this;
}

bool ParticipantsOfTheCompetition::operator==(const ParticipantsOfTheCompetition& Participant) const
{
    return first_name == Participant.first_name && last_name == Participant.last_name && _category == Participant._category && _country == Participant._country && birth_year == Participant.birth_year && id_Participant == Participant.id_Participant;
}

bool ParticipantsOfTheCompetition::operator<(const ParticipantsOfTheCompetition& Participant) const
{
    return last_name < Participant.last_name;
}

bool ParticipantsOfTheCompetition::operator>(const ParticipantsOfTheCompetition& Particicipant) const
{
    return last_name > Particicipant.last_name;
}

std::string ParticipantsOfTheCompetition::FirstName() const
{
    return first_name;
}

std::string ParticipantsOfTheCompetition::LastName() const
{
    return last_name;
}

std::string ParticipantsOfTheCompetition::Country() const
{
    return _country;
}

std::string ParticipantsOfTheCompetition::Category() const
{
    return _category;
}

Date ParticipantsOfTheCompetition::BirthYear() const
{
    return birth_year;
}

unsigned short ParticipantsOfTheCompetition::IDParticipant() const
{
    return id_Participant;
}