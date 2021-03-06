/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     |
    \\  /    A nd           | For copyright notice see file Copyright
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "TimePaths.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::TimePaths::TimePaths
(
    const fileName& rootPath,
    const fileName& caseName,
    const word& systemName,
    const word& constantName
)
:
    processorCase_(caseName.find("processor") != string::npos),
    rootPath_(rootPath),
    case_(caseName),
    system_(systemName),
    constant_(constantName)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::fileName Foam::TimePaths::caseSystem() const
{
    if (processorCase_)
    {
        return ".."/system();
    }
    else
    {
        return system();
    }
}


Foam::fileName Foam::TimePaths::caseConstant() const
{
    if (processorCase_)
    {
        return ".."/constant();
    }
    else
    {
        return constant();
    }
}



// ************************************************************************* //
