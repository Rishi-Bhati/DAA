document.addEventListener('DOMContentLoaded', function() {
    // File structure data
    const fileStructure = {
        'part a': [
            'binary.c',
            'bubble.c',
            'floyds.c',
            'insertion.c',
            'selection.c',
            'string.c',
            'warshall.c'
        ],
        'part b': [
            'bfs.c',
            'dfs.c',
            'heap.c',
            'hors.c',
            'merge.c',
            'quick.c',
            'top.c'
        ]
    };

    // File content cache
    const fileCache = {};

    // DOM elements
    const partAFilesList = document.getElementById('part-a-files');
    const partBFilesList = document.getElementById('part-b-files');
    const codeDisplay = document.getElementById('code-display');
    const currentFileTitle = document.getElementById('current-file');
    const downloadBtn = document.getElementById('download-btn');

    // Populate file lists
    populateFileList(fileStructure['part a'], partAFilesList, 'part a');
    populateFileList(fileStructure['part b'], partBFilesList, 'part b');

    // Function to populate file lists
    function populateFileList(files, listElement, folderName) {
        files.forEach(file => {
            const li = document.createElement('li');
            li.textContent = file;
            li.dataset.path = `${folderName}/${file}`;
            li.addEventListener('click', function() {
                // Remove active class from all list items
                document.querySelectorAll('.file-list li').forEach(item => {
                    item.classList.remove('active');
                });
                
                // Add active class to clicked item
                this.classList.add('active');
                
                // Load and display file content
                loadFileContent(this.dataset.path);
            });
            listElement.appendChild(li);
        });
    }

    // Function to load file content
    function loadFileContent(path) {
        currentFileTitle.textContent = path;
        
        // Check if file content is cached
        if (fileCache[path]) {
            displayFileContent(fileCache[path], path);
            return;
        }

        // Fetch file content
        fetch(`code/${path}`)
            .then(response => {
                if (!response.ok) {
                    throw new Error('File not found');
                }
                return response.text();
            })
            .then(content => {
                // Cache the content
                fileCache[path] = content;
                displayFileContent(content, path);
            })
            .catch(error => {
                console.error('Error loading file:', error);
                codeDisplay.textContent = `// Error loading file: ${error.message}`;
                hljs.highlightElement(codeDisplay);
                downloadBtn.disabled = true;
            });
    }

    // Function to display file content
    function displayFileContent(content, path) {
        codeDisplay.textContent = content;
        hljs.highlightElement(codeDisplay);
        
        // Enable download button
        downloadBtn.disabled = false;
        downloadBtn.onclick = function() {
            downloadFile(content, path.split('/').pop());
        };
    }

    // Function to download file
    function downloadFile(content, filename) {
        const blob = new Blob([content], { type: 'text/plain' });
        const url = URL.createObjectURL(blob);
        const a = document.createElement('a');
        a.href = url;
        a.download = filename;
        document.body.appendChild(a);
        a.click();
        document.body.removeChild(a);
        URL.revokeObjectURL(url);
    }
});
