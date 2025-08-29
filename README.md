# STM32F4 Jenkins CI

[![C](https://img.shields.io/badge/C-95%2F99%2F11%2F17%2F23-blue)](https://en.cppreference.com/index.html)
[![License](https://img.shields.io/badge/license-MIT-green)](https://github.com/abelbarreira/stm32f4_jenkins_ci/blob/main/LICENSE)
[![Pull Requests Welcome](https://img.shields.io/badge/pull%20requests-welcome-brightgreen.svg)](https://github.com/abelbarreira/stm32f4_jenkins_ci/blob/main/.github/CONTRIBUTING.md)

## About The Project

STM32F4 Jenkins CI project deploys **[Jenkins](https://www.jenkins.io/)** local server where a `STM32F407G-DISC1` discovery board is connected in order to build, load (flash) using [OpenOCD](https://openocd.org/) and execute **[Unity](https://www.throwtheswitch.org/unity)** tests.

This is is based in [STM32F4 Basic](https://github.com/abelbarreira/stm32f4_basic).

## Environment

This environment is ready to work with [Git and Git Bash Scripts](https://git-scm.com/downloads) with [Visual Studio Code](https://code.visualstudio.com/) using following profile:

- `tools/vscode/stm32f4_socrates.code-profile`

## Setup

The project will probably end up with a [Docker](https://www.docker.com/) container to centralize the full setup. In addition, here is the local setup environment:

- `scripts/setup_linux.sh`, or similar setup for Windows [I will work on this]
  - For Windows:
    - Compilers:
      - A good choice is [MSYS2](https://www.msys2.org/) with [`UCRT64` environment](https://www.msys2.org/docs/environments/#__tabbed_1_1)
      - Path: `C:\\msys64\\usr\\bin`
    - OpenOCD:
      - [Download pre-built OpenOCD for Windows](https://gnutoolchains.com/arm-eabi/openocd/) like `openocd-20250710.7z`
      - Path: `C:\\OpenOCD-20250710-0.12.0\\bin`
- `scripts/setup_python.sh`
  - Requires [`pyenv`](https://github.com/pyenv/pyenv)
- `scripts/stm32f4_drivers_add_or_update_subs.sh`
- `scripts/unity_add_or_update_sub.sh` (for Unity Testing)

## Documentation

Refer to [SUMMARY](docs/SUMMARY.md).

## Contributing

If you have suggestions for how Open Source Projects Template could be improved, or want to report a bug, open an issue! We'd love all and any contributions.

For more, check out the [Contributing Guide](.github/CONTRIBUTING.md).

## License

MIT License

Copyright (c) 2025 abelbarreira

For more, check out the [License File](LICENSE).
