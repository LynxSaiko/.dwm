#!/bin/bash
set -e

BIN_DIR="/usr/bin"
APP_DIR="/usr/share/applications"
MERGED_MENU_DIR="/etc/xdg/menus/applications-merged"

# Ambil semua kategori X-BlackArch-* dari file menu
echo "🔍 Memindai kategori dari $MERGED_MENU_DIR..."
mapfile -t category_list < <(grep -rhoP '<Category>X-BlackArch-[^<]+' "$MERGED_MENU_DIR" | cut -d'>' -f2 | sort -u)

generate_desktop() {
    local appname="$1"
    local category="$2"
    local path="$BIN_DIR/$appname"
    local desktop_file="$APP_DIR/$appname.desktop"

    # Skip jika tidak executable
    [[ -x "$path" ]] || return

    # Skip jika file .desktop sudah ada
    if [[ -f "$desktop_file" ]]; then
        echo "⏭️  Skip: $desktop_file sudah ada"
        return
    fi

    echo "✅ Membuat: $desktop_file (Kategori: $category)"
    cat <<EOF | sudo tee "$desktop_file" > /dev/null
[Desktop Entry]
Name=$appname
Exec=$path
Icon=utilities-terminal
Terminal=true
Type=Application
Categories=$category;
EOF
}

# Loop semua kategori dan cocokkan dengan nama binary
echo "🚀 Memproses tools pentesting dari kategori BlackArch..."
for category in "${category_list[@]}"; do
    suffix="${category#X-BlackArch-}"
    suffix_lc=$(echo "$suffix" | tr 'A-Z' 'a-z')

    for bin in "$BIN_DIR"/*; do
        appname=$(basename "$bin")
        name_lc=$(echo "$appname" | tr 'A-Z' 'a-z')

        # Kecocokan nama tool dan kategori
        if [[ "$name_lc" == *"$suffix_lc"* ]]; then
            generate_desktop "$appname" "$category"
        fi
    done
done

echo "🎯 Selesai. Semua .desktop tools BlackArch yang belum ada berhasil dibuat."

