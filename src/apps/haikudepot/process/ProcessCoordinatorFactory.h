/*
 * Copyright 2018-2025, Andrew Lindesay <apl@lindesay.co.nz>.
 * All rights reserved. Distributed under the terms of the MIT License.
 */
#ifndef PROCESS_COORDINATOR_FACTORY_H
#define PROCESS_COORDINATOR_FACTORY_H

#include <SupportDefs.h>

#include "AbstractProcess.h"
#include "PackageInfo.h"
#include "PackageScreenshotRepository.h"

class Model;
class PackageInfoListener;
class ProcessCoordinator;
class ProcessCoordinatorListener;
class UserDetailVerifierListener;

/*! This class is able to create ProcessCoordinators that are loaded-up with
    Processes that together complete some larger job.
*/

class ProcessCoordinatorFactory {
public:
	static	ProcessCoordinator*	CreateIncrementViewCounter(Model* model,
									const PackageInfoRef package);

	static	ProcessCoordinator*	CreateBulkLoadCoordinator(Model* model, bool forceLocalUpdate);

	static	ProcessCoordinator*	CreateUserDetailVerifierCoordinator(
									UserDetailVerifierListener* userDetailVerifierListener,
									Model* model);

	static	ProcessCoordinator*	CreatePackageActionCoordinator(
									Model* model, BMessage* message);

	static	ProcessCoordinator*	CacheScreenshotCoordinator(
									Model* model, ScreenshotCoordinate& screenshotCoordinate);

	static	ProcessCoordinator*	PopulatePkgChangelogCoordinator(Model* model,
									const BString& packageName);

	static	ProcessCoordinator*	PopulatePkgUserRatingsCoordinator(Model* model,
									const BString& packageName);

private:
	static	uint32				_CalculateServerProcessOptions();

	static	BString				_ExtractPackageNameFromMessage(BMessage* message);

	static	ProcessCoordinator*	_CreateInstallPackageActionCoordinator(
									Model* model, BMessage* message);

	static	ProcessCoordinator*	_CreateUninstallPackageActionCoordinator(
									Model* model, BMessage* message);

	static	ProcessCoordinator*	_CreateOpenPackageActionCoordinator(
									Model* model, BMessage* message);

	static	ProcessCoordinator*	_CreateSingleProcessCoordinator(const char* name,
									AbstractProcess *process);

};

#endif // PROCESS_COORDINATOR_FACTORY_H
