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
    const pdfFile = document.getElementById('pdf-file');
    const codeDisplay = document.getElementById('code-display');
    const codeContainer = document.getElementById('code-container');
    const pdfContainer = document.getElementById('pdf-container');
    const pdfViewer = document.getElementById('pdf-viewer');
    const currentFileTitle = document.getElementById('current-file');
    const downloadBtn = document.getElementById('download-btn');
    const copyBtn = document.getElementById('copy-btn');
    const themeToggleBtn = document.getElementById('theme-toggle-btn');
    const htmlElement = document.documentElement;

    // Theme management
    const currentTheme = localStorage.getItem('theme') || 'light';
    htmlElement.setAttribute('data-theme', currentTheme);
    updateThemeIcon(currentTheme);

    // Populate file lists
    populateFileList(fileStructure['part a'], partAFilesList, 'part a');
    populateFileList(fileStructure['part b'], partBFilesList, 'part b');

    // Theme toggle functionality
    themeToggleBtn.addEventListener('click', function() {
        const currentTheme = htmlElement.getAttribute('data-theme');
        const newTheme = currentTheme === 'light' ? 'dark' : 'light';
        
        htmlElement.setAttribute('data-theme', newTheme);
        localStorage.setItem('theme', newTheme);
        
        updateThemeIcon(newTheme);
        
        // Re-highlight code if visible
        if (codeContainer.style.display !== 'none') {
            hljs.highlightElement(codeDisplay);
        }
    });

    function updateThemeIcon(theme) {
        const icon = themeToggleBtn.querySelector('i');
        if (theme === 'dark') {
            icon.className = 'fas fa-sun';
        } else {
            icon.className = 'fas fa-moon';
        }
    }

    // PDF file click handler
    pdfFile.addEventListener('click', function() {
        // Remove active class from all list items
        document.querySelectorAll('.file-list li').forEach(item => {
            item.classList.remove('active');
        });
        
        // Add active class to clicked item
        this.classList.add('active');
        
        // Show PDF viewer, hide code display
        codeContainer.style.display = 'none';
        pdfContainer.style.display = 'block';
        
        // Set the PDF source
        pdfViewer.src = 'DAAA.pdf';
        
        // Update title and enable download button
        currentFileTitle.textContent = 'DAAA.pdf';
        downloadBtn.disabled = false;
        downloadBtn.onclick = function() {
            window.open('DAAA.pdf', '_blank');
        };
        
        // Disable copy button for PDF
        copyBtn.disabled = true;
    });

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
        
        // Show code container, hide PDF viewer
        codeContainer.style.display = 'block';
        pdfContainer.style.display = 'none';
        
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
        
        // Enable copy button
        copyBtn.disabled = false;
        copyBtn.onclick = function() {
            copyToClipboard(content);
        };
    }
    
    // Function to copy code to clipboard
    function copyToClipboard(text) {
        navigator.clipboard.writeText(text)
            .then(() => {
                // Visual feedback for successful copy
                copyBtn.classList.add('copy-success');
                copyBtn.textContent = 'Copied!';
                
                // Reset button after 2 seconds
                setTimeout(() => {
                    copyBtn.classList.remove('copy-success');
                    copyBtn.textContent = 'Copy Code';
                }, 2000);
            })
            .catch(err => {
                console.error('Failed to copy text: ', err);
                copyBtn.textContent = 'Copy Failed';
                
                // Reset button after 2 seconds
                setTimeout(() => {
                    copyBtn.textContent = 'Copy Code';
                }, 2000);
            });
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
