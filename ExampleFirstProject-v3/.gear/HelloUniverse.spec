%define _unpackaged_files_terminate_build 1

Name:    HelloUniverse
Version: 3.0
Release: alt1
Summary: Most simple RPM package
License: GPL-1.0
Group:   Development/Other
Source:  %name-%version.tar
Patch:	 %name-%version-%release.patch
BuildRequires: gcc-c++

%description
This is my first RPM

%prep
%setup -n %name

%build
%make_build HelloUniverse

%install
mkdir -p %{buildroot}%_bindir
install -m 755 HelloUniverse %{buildroot}%_bindir

%files
%_bindir/%name

%changelog
* Wed Mar 05 2025 Alexander Hacker <alexander@email.address> 3.0-alt1
- Updated to new version v3.0.

* Mon Apr 01 2024 Some One <someone@altlinux.org> 1.0-alt1
- Init Build

